#ifndef GAME_H
# define GAME_H

#include <ncurses.h>
#include "Player.hpp"
#include "Enemy.hpp"
#include "Bullet.hpp"
#include <panel.h>
#include <iostream>
#include "Player.hpp"

#define NUM_BULLETS 4

class Game{
    private:
        WINDOW *score_board;
        WINDOW *game_board;
        int game_board_width;
        int game_board_height;
        int num_enemies;
        Player * plyr;
        Enemy **enemies;
    
    public:
        Game();
        ~Game();
        Game (Game const & copy);
        Game& operator=(Game const &rhs);

        void set_score_board(WINDOW * sc_b);
        void set_game_board(WINDOW * gm_b);
        WINDOW* get_score_board() const;
        WINDOW* get_game_board() const;
        int get_game_board_width() const;
        int get_game_board_height() const;

        Player * get_player() const;
        void set_player(Player * player);
        
        Enemy ** get_enemies() const;
        int get_num_enemies() const;
        void set_num_enemies(int n);
        void add_enemies(Enemy **enemies);

        void set_bullet_burst(int n);
		void checkCollisions();

        void action(int key);

        void update_screen();
        void init_screen();

        void run();
        void clean();
};

#endif
