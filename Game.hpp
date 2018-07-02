#ifndef GAME_H
# define GAME_H

#include <ncurses.h>
#include "Player.hpp"
#include "Enemy.hpp"
#include "Bullet.hpp"
#include <panel.h>
#include <iostream>
#include "Player.hpp"
#include <sys/timeb.h>
#include <time.h>

#define NUM_BULLETS 4
#define TIME_DELTA 200

class Game{
    private:
        WINDOW *score_board;
        WINDOW *game_board;
        int game_board_width;
        int game_board_height;
        int num_enemies;
        Player * plyr;
        Enemy **enemies;
		long long int time_t0;
		long long int time_last_delta;
		long long int time_delta;
		struct timeb timer_msec;
		long long int timestamp_msec;
    
    public:
        Game();
        ~Game();
        Game (Game const & copy);
        Game& operator=(Game const &rhs);

		long long int getTimeDelta();
		long long int getTimeSinceInit();
		void updateTimeDelta();

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
