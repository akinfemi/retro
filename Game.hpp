#ifndef GAME_H
# define GAME_H

#include <ncurses.h>
#include "Player.hpp"
#include "Enemy.hpp"
#include "Bullet.hpp"
#include <panel.h>
#include <iostream>
#include "Player.hpp"

class Game{
    private:
        WINDOW *score_board;
        WINDOW *game_board;
        int game_board_width;
        int game_board_height;
        int num_enemies;
        int num_bullets;
        Player plyr;
        Enemy *enemies;
        Bullet * bullets;
    
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

        Player get_player() const;
        Enemy * get_enemies() const;
        int get_num_enemies() const;
        void set_num_enemies(int n);
        void set_bullet_burst(int n);

        void add_bullet(Bullet& bullet);
        Bullet *get_bullets();
        int get_num_bullets() const;

        void update_screen();
        void init_screen();
        void set_player(Player& player);
        void add_enemies(Enemy *enemies);
        void run();
        void clean();
};

#endif
