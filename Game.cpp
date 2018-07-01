#include "Game.hpp"

Game::Game()
{
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

	WINDOW *retro_world;
	int offset_x, offset_y, max_x, max_y;
	printw("Press escape key to exit.");
	refresh();
	// COLS & LINES are filled in during initscr().
	offset_x = (COLS - WORLD_WIDTH) / 2;
	offset_y = (LINES - WORLD_HEIGHT) / 2;

	retro_world = newwin(WORLD_HEIGHT,
			WORLD_WIDTH,
			offset_y,
			offset_x);

	box(retro_world, 0, 0);
	wrefresh(retro_world);

	/*
	https://www.gnu.org/software/guile-ncurses/manual/html_node/Getting-characters-from-the-keyboard.html
	*/
	while (1) {
		int keyPress = getch();
		if (keyPress == 27) { // Escape key
			return;
		}
	}
}

void Game::clean()
{
	endwin();
}
