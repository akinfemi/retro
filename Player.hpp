#ifndef PLAYER_H
# define PLAYER_H

#include "GameEntity.hpp"
#include "Bullet.hpp"

class Player : public GameEntity {
    private:
        EntityType type;
        Bullet ** bullets;
        int num_bullets;

    public:
        Player();
        ~Player();
        Player& operator=(Player const & rhs);
        Player(Player const & copy);

        void add_bullets();
        Bullet **get_bullets();
        int get_num_bullets() const;

        //overide
        void shoot(WINDOW *win);
        void draw(WINDOW *win);
};

#endif
