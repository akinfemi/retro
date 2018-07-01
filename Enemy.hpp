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

        void move();
        void draw();

        //Bonus function
        void shoot();
};
#endif