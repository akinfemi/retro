#ifndef BULLET_H
# define BULLET_H
#include "GameEntity.hpp"

class Bullet : public GameEntity {
    private:
        EntityType type;

    public:
        Bullet();
        ~Bullet();
        Bullet& operator=(Bullet const & rhs);
        Bullet(Bullet const & copy);

        void move();
        void draw();
        void shoot(); //override just to make it a concrete class
};

#endif