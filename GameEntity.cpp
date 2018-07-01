#include "GameEntity.hpp"

GameEntity::GameEntity(){}

GameEntity::~GameEntity(){}

GameEntity::GameEntity(GameEntity const & copy){
    *this = copy;
}

GameEntity& GameEntity::operator=(GameEntity const & rhs) {
    this->x_loc = rhs.getX();
    this->y_loc = rhs.getY();
    this->type = rhs.getType();
    this->health = rhs.getHealth();
    return (*this);
}

void GameEntity::move(Direction dir, Speed spd){
    if (dir == UP){
        this->setY(this->getY() - (1 * spd));
    }else if (dir == LEFT){
        this->setX(this->getX() - (1 * spd));
    }
    else if (dir == RIGHT){
        this->setX(this->getX() + (1 * spd));
    }
    else if (dir == DOWN){
        this->setY(this->getY() + (1 * spd));
    }
}

void GameEntity::die(){
    this->alive = false;
}

void GameEntity::kill(GameEntity &entity){
    entity.alive = false;
}

int GameEntity::getX() const{
    return this->x_loc;
}

int GameEntity::getY() const{
    return this->y_loc;
}

void GameEntity::setX(int x){
    this->x_loc = x;
}

void GameEntity::setY(int y){
    this->y_loc = y;
}

EntityType GameEntity::getType() const{
    return this->type;
}

void GameEntity::setType(EntityType type){
    this->type = type;
}

int GameEntity::getHealth() const{
    return this->health;
}

void GameEntity::setHealth(int health){
    this->health = health;
}
