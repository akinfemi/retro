#ifndef GAME_H
# define GAME_H

#include <ncurses.h>

class Game{
    private:
        WINDOW *score_board;
        WINDOW *game_board;
    
    public:
        Game();
        ~Game();
        Game (Game const & copy);
        Game& operator=(Game const &rhs);

        void update_screen();
        void init_screen();
        void add_player();
        void run();
        void clean();
};

#endif