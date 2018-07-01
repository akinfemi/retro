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
};

#endif