#ifndef GAME_H
# define GAME_H

#include <ncurses.h>
#include <panel.h>
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

        void set_score_board(WINDOW * sc_b);
        void set_game_board(WINDOW * gm_b);
        WINDOW* get_score_board();
        WINDOW* get_game_board();

        void update_screen();
        void init_screen();
        void add_player();
		void add_enemies();
        void run();
        void clean();
};

#endif
