#include "Game.hpp"

int main(void)
{
    Game game;
    // game.set_num_enemies(16);
    // game.set_bullet_burst(8);
    Enemy ** enemies = new Enemy*[game.get_num_enemies()];
    
    game.add_enemies(enemies);
    game.run();
    game.clean();
    return 0;
}
