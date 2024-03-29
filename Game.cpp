#include "Game.hpp"

#define MAX_WIDTH 156
#define MAX_HEIGHT 47
#define SPACE 32
#define N_ROWS 4
#include <unistd.h>

Game::Game()
{
    this->level = 0;
    this->score = 0;
    init_screen();
    srand(time(NULL));

    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_CYAN, COLOR_RED);

    keypad(stdscr, TRUE); // Fixes arrow keys (UP, DOWN, LEFT, RIGHT) getting mixed with Escape character
	int offset_x, offset_y;//, max_x, max_y;

	/* COLS & LINES variables are set during ncurses initscr(). */
    offset_x = COLS / 10;
	offset_y = LINES / 20;
	set_game_board(newwin(MAX_HEIGHT - 10, MAX_WIDTH - 50, 5, 45));
	nodelay(stdscr, TRUE); // Allows getch() to be non-blocking and not pause on user input.

    set_score_board(newwin(MAX_HEIGHT - 10, 40, 5, 5));
    box(score_board, 0,0);
    wbkgd(score_board, COLOR_PAIR(1));
    wrefresh(score_board);

    this->num_enemies = 96;

    Player *plyr = new Player();
    plyr->setX((MAX_WIDTH / 2) - 27);
    plyr->setY(MAX_HEIGHT - 13);
    plyr->alive = true;
    this->set_player(plyr);

    std::cout << "Game is starting..." << std::endl;

	/* Getting the time since epoch in milliseconds. */
	ftime(&timer_msec);
	this->timestamp_msec = ((long long int) timer_msec.time) * 1000ll + (long long int) timer_msec.millitm;
	this->time_t0 = this->timestamp_msec;
	this->time_last_delta = this->timestamp_msec;
	this->time_delta = 0;
	// std::cout << timestamp_msec << std::endl;
}

Game::~Game(){
    this->clean();
	std::cout << "Game has exited." << std::endl;
}

Game::Game(Game const & copy){
    *this = copy;
}

Game& Game::operator=(Game const & rhs){
    this->score_board = rhs.get_score_board();
    this->game_board = rhs.get_game_board();
    this->plyr = rhs.get_player();
    this->enemies = rhs.get_enemies();
    this->num_enemies = rhs.get_num_enemies();
    this->game_board_width = get_game_board_width();
    this->game_board_height = get_game_board_height();
    return (*this);
}

void Game::set_score_board(WINDOW *sc_b){
    this->score_board = sc_b;
}

void Game::set_game_board(WINDOW *gm_b){
    this->game_board = gm_b;
}

WINDOW* Game::get_score_board() const{
    return this->score_board;
}

WINDOW* Game::get_game_board() const{
    return this->game_board;
}

int Game::get_game_board_width() const{
    return this->game_board_width;
}
int Game::get_game_board_height() const{
    return this->game_board_height;
}

Player * Game::get_player() const{
    return this->plyr;
}

Enemy ** Game::get_enemies() const{
    return this->enemies;
}

int Game::get_num_enemies() const {
    return this->num_enemies;
}

void Game::set_num_enemies(int n){
    this->num_enemies = n;
}

// Return the time since last "tick". Milliseconds.
long long int Game::getTimeDelta(){
	return this->time_delta;
}

void Game::updateTimeDelta() {
	ftime(&timer_msec);
	this->timestamp_msec = ((long long int) timer_msec.time) * 1000ll + (long long int) timer_msec.millitm;
	this->time_delta = this->timestamp_msec - this->time_last_delta;
	if (this->time_delta >= TIME_DELTA)
	{
		this->time_delta = 0;
		this->time_last_delta = this->timestamp_msec;
	}
}

long long int Game::getTimeSinceInit(){
	ftime(&timer_msec);
	this->timestamp_msec = ((long long int) timer_msec.time) * 1000ll + (long long int) timer_msec.millitm;
	return this->timestamp_msec - this->time_t0;
}

void Game::update_screen(){
    int dead_enemies = 0;
	if (this->time_delta == 0)
	{
        wclear(game_board);
        Enemy ** enemies;

        enemies = get_enemies();
        for (int i = 0; i < this->get_num_enemies(); i++){
            if (enemies && enemies[i] && enemies[i]->alive){
                enemies[i]->setY(enemies[i]->getY() + 1);
                if (enemies[i]->getY() > MAX_HEIGHT){
                    enemies[i]->alive = false;
                }
                enemies[i]->draw(this->get_game_board());
            }
            else
            {
                dead_enemies += 1;
            }
        }
        if (this->get_player() && this->get_player()->alive){
            this->get_player()->draw(this->get_game_board());
        }
        checkCollisions();
        if (dead_enemies == this->get_num_enemies()){
            this->add_enemies(enemies);
            this->level += 1;
            dead_enemies = 0;
        }	
        /* Score Board */
        wclear(score_board);
        wprintw(score_board, "\n TIME: %d\n", this->getTimeSinceInit()/1000);
        wprintw(score_board, "\n SCORE: %d\n", this->score);
        wprintw(score_board, " LEVEL: %d", this->level);
        box(score_board, 0, 0);
        wrefresh(score_board);
	}

}

Enemy ** Game::spawn_enemies(){
    Enemy ** enemies = new Enemy*[this->get_num_enemies()];
    for (int i = 0; i < this->get_num_enemies(); i++){
        enemies[i] = new Enemy();
    }
    return enemies;
}

void Game::set_player(Player * player){
    this->plyr = player;
}

void Game::add_enemies(Enemy ** enemies){
    int i = 0;
    for (int j = 0; j < N_ROWS; j++){
        int x = 5;
        int y = 1 + (3 * j);
        for (int k = 0; k < this->get_num_enemies() / N_ROWS; k++){
            // enemies[i] = new Enemy();
            enemies[i]->setX( x );
            enemies[i]->setY( y );
            enemies[i]->alive = rand() % 2;;
            x += 4;
            i++;
        }
    }
    this->enemies = enemies;
}

void Game::init_screen()
{
	initscr(); // Initialize the window
	noecho(); // Don't echo any keypresses
	curs_set(FALSE); // Don't display a cursor
	printw("Press x key to exit.");
	refresh();
}

void Game::run()
{
	/* Game loop */
    if (!this->get_player())
        return ;
	while (this->get_player()->alive) {
		updateTimeDelta();
		// printw("TIME_DELTA: %lld ", this->getTimeDelta());
		int keyPress = getch();
		if (keyPress == 'X' or keyPress == 'x') {
			return;
		}
		else if (keyPress == KEY_UP ||
				keyPress == KEY_DOWN ||
				keyPress == KEY_RIGHT ||
				keyPress == KEY_LEFT ||
                keyPress == ' ')
		{
            action(keyPress);
		}
		else {
			update_screen();
	        box(game_board, 0, 0);
            wbkgd(game_board, COLOR_PAIR(1));
	        wrefresh(game_board);
		}
	}
}

void Game::action(int key){
    Direction dir;
    if (key == SPACE){
        this->get_player()->shoot(game_board);
    }else //move
    {
        dir = (Direction)(KEY_RIGHT - key);
        this->get_player()->move_entity(dir, NORMAL);
    }
}

void Game::checkCollisions(){
    Bullet **bullets;
    int health = 0;
    if (!this->plyr || !this->get_enemies())
        return ;
    bullets = this->plyr->get_bullets();
    if (bullets){
    for (int i = 0; i < this->plyr->get_num_bullets(); i++){
        if (bullets[i]->alive == true){
            for (int j = 0; j < this->get_num_enemies(); j++){
                if (std::abs(bullets[i]->getX() - this->get_enemies()[j]->getX()) <= 2 &&
                        std::abs(bullets[i]->getY() - this->get_enemies()[j]->getY()) <= 1)
                        {
                            health = this->get_enemies()[j]->getHealth();
                            if (health <= 1){
                                this->get_enemies()[j]->alive = false;
                                this->score += 10;
                            }
                            bullets[i]->alive = false;
                            break;
                        }
            }
        }
    }
    }
    for (int i = 0; i < this->get_num_enemies(); i++){
		if (std::abs(this->plyr->getX() - this->get_enemies()[i]->getX()) <= 2 &&
				std::abs(this->plyr->getY() - this->get_enemies()[i]->getY()) <= 1)
                {
                    if (this->get_enemies()[i]->alive == true){
            			this->plyr->alive = false;
                    }
                }
    }
}

void Game::clean()
{
    delwin(score_board);
    delwin(game_board);
	endwin();
}
