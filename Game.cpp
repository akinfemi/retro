#include "Game.hpp"

Game::Game()
{
	std::cout << "Game is starting..." << std::endl;
	player1 = new Player();
	init_screen();
}

Game::~Game()
{
	std::cout << "Game has exited." << std::endl;
}

Game::Game(Game const &copy)
{
	*this = copy;
}

Game& Game::operator=(Game const &rhs)
{
	(void)rhs;
	return *this;
}

void Game::update_screen()
{
	refresh();
}

void Game::init_screen()
{
	initscr(); // Initialize the window
	noecho(); // Don't echo any keypresses
	curs_set(FALSE); // Don't display a cursor
	refresh();
}

void Game::add_player()
{

}

void Game::add_enemies()
{
}

#define WORLD_WIDTH 50
#define WORLD_HEIGHT 20
void Game::run()
{
	int offset_x, offset_y, max_x, max_y;
	refresh();

	/* COLS & LINES variables are set during initscr(). */
	offset_x = (COLS - WORLD_WIDTH) / 2;
	offset_y = (LINES - WORLD_HEIGHT) / 2;

	game_board = newwin(WORLD_HEIGHT, WORLD_WIDTH, offset_y, offset_x);
	nodelay(stdscr, TRUE); // Allows getch() to be non-blocking and not pause on user input.
	keypad(stdscr, TRUE); // Fixes arrow keys (UP, DOWN, LEFT, RIGHT) getting mixed with Escape character
	box(game_board, 0, 0);
	wrefresh(game_board);

	/* Game loop */
	while (1) {
		int keyPress = getch();
		if (keyPress == 'X' or keyPress == 'x') {
			return;
		}
		else if (keyPress == KEY_UP ||
				keyPress == KEY_DOWN ||
				keyPress == KEY_RIGHT ||
				keyPress == KEY_LEFT)
		{
			printw("Keypress detected.");
		}
		else
			update_screen();
	}
}

void Game::clean()
{
	endwin();
}
