#ifndef ENEMY_H
# define ENEMY_H
#include "GameEntity.hpp"

class Enemy : public GameEntity {
    private:
        EntityType type;
        int bullets_to_kill;

    public:
        Enemy();
        ~Enemy();
        Enemy& operator=(Enemy const & rhs);
        Enemy(Enemy const & copy);

        //Bonus functions
        void shoot();
        void move();
};
#endif