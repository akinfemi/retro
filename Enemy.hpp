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

        void draw();

        int get_bullets_to_kill() const;
        //Bonus function
        void shoot();
};
#endif