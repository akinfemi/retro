#ifndef PLAYER_H
# define PLAYER_H

#include "GameEntity.hpp"

class Player : public GameEntity {
    private:
        EntityType type;

    public:
        Player();
        ~Player();
        Player& operator=(Player const & rhs);
        Player(Player const & copy);

        //overide
        void shoot(WINDOW *win);
        void draw(WINDOW *win);
};

#endif
