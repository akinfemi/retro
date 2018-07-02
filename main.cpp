#include "Game.hpp"

int main(void)
{
    Game game;
    // game.set_num_enemies(16);
    // game.set_bullet_burst(8);
    Enemy ** enemies = game.spawn_enemies();
    game.add_enemies(enemies);
    game.run();
    game.clean();
    return 0;
}
