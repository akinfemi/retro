#include "GameEntity.hpp"

GameEntity::GameEntity(){}

GameEntity::~GameEntity(){}

GameEntity::GameEntity(GameEntity const & copy){
    *this = copy;
}

GameEntity& GameEntity::operator=(GameEntity const & rhs){
    this->x_loc = rhs.getX();
    this->y_loc = rhs.getY();
    this->type = rhs.getType();
    this->health = rhs.getHealth();
    return (*this);
}