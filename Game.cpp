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
	int y, x = 0;
	initscr(); // Initialize the window
	noecho(); // Don't echo any keypresses
	curs_set(FALSE); // Don't display a cursor

	/*
	https://linux.die.net/man/3/getmaxyx
	*/
	getmaxyx(stdscr, y, x); // Global var 'stdscr' is created by the call to `initscr()`

	score_board = newwin(10, 40, 2, 5);
	game_board = newwin(10, 40, 4, 6);
	getch();
	endwin();

}

void Game::add_player()
{

}

void Game::add_enemies()
{
}

void Game::run()
{

}

void Game::clean()
{

}
