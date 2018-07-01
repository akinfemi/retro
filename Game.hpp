#ifndef GAME_H
# define GAME_H

#include <ncurses.h>
#include <iostream>

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
		void add_enemies();
        void run();
        void clean();
};

#endif
