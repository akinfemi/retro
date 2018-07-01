#include "Game.hpp"

int main(void)
{
    Game game;

    game.init_screen();
    game.add_player();
    game.add_enemies();
    game.run();
    game.clean();
    return 0;
}