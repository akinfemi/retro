#include "Game.hpp"

#define MAX_WIDTH 156
#define MAX_HEIGHT 47
#define SPACE 32
#define N_ROWS 4

Game::Game()
{
	std::cout << "Game is starting..." << std::endl;

    init_screen();

    keypad(stdscr, TRUE); // Fixes arrow keys (UP, DOWN, LEFT, RIGHT) getting mixed with Escape character
	int offset_x, offset_y;//, max_x, max_y;

	/* COLS & LINES variables are set during ncurses initscr(). */
    offset_x = COLS / 10;
	offset_y = LINES / 20;
	set_game_board(newwin(MAX_HEIGHT - 10, MAX_WIDTH - 50, 5, 45));
	nodelay(stdscr, TRUE); // Allows getch() to be non-blocking and not pause on user input.

    set_score_board(newwin(MAX_HEIGHT - 10, 40, 5, 5));
    box(score_board, 0,0);
    wrefresh(score_board);

    this->num_bullets = NUM_BULLETS;
    this->num_enemies = 96;

    Player *plyr = new Player();
    plyr->setX((MAX_WIDTH / 2) - 27);
    plyr->setY(MAX_HEIGHT - 13);
    plyr->alive = true;
    this->set_player(plyr);

    std::cout << "Game is starting..." << std::endl;
}

Game::~Game(){
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
    this->num_bullets = rhs.get_num_bullets();
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

void Game::set_bullet_burst(int n){
    this->num_bullets = n;
}

void Game::add_bullet(Bullet &bullet){
    Bullet *bullets = this->get_bullets();
    for (int i = 0; i < get_num_bullets(); i++){
        if (bullets[i].alive == false){
            bullets[i].setX(bullet.getX());
            bullets[i].setY(bullet.getY());

            bullets[i].setX(50);
            bullets[i].setY(50);
            bullets[i].alive = true;
        }
    }
}

Bullet * Game::get_bullets(){
    return this->bullets;
}

int Game::get_num_bullets() const {
    return this->num_bullets;
}

void Game::update_screen(){
    wclear(game_board);
    Enemy ** enemies;

    enemies = get_enemies();
    for (int i = 0; i < this->get_num_enemies(); i++){
        if (enemies && enemies[i] && enemies[i]->alive){
            enemies[i]->draw(this->get_game_board());
        }
    }

    if (this->get_player()->alive)
        this->get_player()->draw(this->get_game_board());
    
    for (int i = 0; i < this->get_num_bullets(); i++){
            bullets[i].draw(game_board);
	}
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
            enemies[i] = new Enemy();
            enemies[i]->setX( x );
            enemies[i]->setY( y );
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
	// for (int i = 0; i < this->get_num_bullets(); i++)
	// {
	// 	bullets[i].setX(78);
	// 	bullets[i].setY(10);
	// }
	refresh();
}

void Game::run()
{
	/* Game loop */
	while (this->get_player()->alive) {
        
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
		else{
			update_screen();
            box(game_board, 0, 0);
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

void Game::clean()
{
    delwin(score_board);
    delwin(game_board);
	endwin();
}
