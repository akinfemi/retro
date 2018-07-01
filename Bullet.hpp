#ifndef BULLET_H
# define BULLET_H
#include "GameEntity.hpp"
#include <ncurses.h>

class Bullet : public GameEntity {
    private:
        EntityType type;
        void shoot(WINDOW *win); //override just to make it a concrete class

    public:
        Bullet();
        ~Bullet();
        Bullet& operator=(Bullet const & rhs);
        Bullet(Bullet const & copy);

        void draw(WINDOW *win);
};

#endif