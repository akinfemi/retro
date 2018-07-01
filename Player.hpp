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

        void move();
};

#endif