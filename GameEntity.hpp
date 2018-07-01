#ifndef GAME_ENTITY_H
# define GAME_ENTITY_H

#include <ncurses.h>

enum EntityType {ENEMY = 1, PLAYER, BULLET};
enum Direction {UP, DOWN, RIGHT, LEFT};
enum Speed {NORMAL = 1, FAST, SUPER_FAST};

class GameEntity{
    private:
        int x_loc;
        int y_loc;
        EntityType type;
        int health;

    public:
        bool alive;
        GameEntity();
        ~GameEntity();
        GameEntity& operator=(GameEntity const & rhs);
        GameEntity(GameEntity const & copy);
        virtual void move(Direction dir, Speed spd);
        virtual void die();
        virtual void kill(GameEntity &entity);
        virtual void shoot(WINDOW *win) = 0;
        virtual void draw(WINDOW *win) = 0;

        virtual int getX() const;
        virtual int getY() const;
        virtual void setX(int x);
        virtual void setY(int y);

        virtual EntityType getType() const;
        virtual void setType(EntityType tpe);
        virtual int getHealth() const;
        virtual void setHealth(int hlth);
};

#endif
