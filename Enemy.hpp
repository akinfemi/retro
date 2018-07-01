#ifndef ENEMY_H
# define ENEMY_H
#include "GameEntity.hpp"
#include <ncurses.h>
class Enemy : public GameEntity {
    private:
        EntityType type;
        int bullets_to_kill;

    public:
        Enemy();
        ~Enemy();
        Enemy& operator=(Enemy const & rhs);
        Enemy(Enemy const & copy);

        void draw(WINDOW *win);

        //Bonus function
        int get_bullets_to_kill() const;
        void shoot(WINDOW *win);
};
#endif