#ifndef PLAYER_H
# define PLAYER_H
#include "GameEntity.hpp"
#include "Game.hpp"

class Player : public GameEntity {
    private:
        EntityType type;
        Game game;

    public:
        Player();
        ~Player();
        Player& operator=(Player const & rhs);
        Player(Player const & copy);

        //overide
        void move();
        void shoot();
        void draw();
};

#endif