#ifndef GAME_ENTITY_H
# define GAME_ENTITY_H

enum EntityType {ENEMY = 1, PLAYER, BULLET};

class GameEntity{
    private:
        int x_loc;
        int y_loc;
        EntityType type;
        int health;

    public:
        virtual void move() = 0;
        virtual void die();
        virtual void kill(GameEntity &entity);
        virtual void shoot() = 0;

        virtual int getX();
        virtual int getY();
        virtual void setX(int x);
        virtual void setY(int y);
};

#endif