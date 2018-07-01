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

void GameEntity::move() {}

void GameEntity::die() {}

void GameEntity::kill(GameEntity &entity) {}

void GameEntity::shoot() {}

/* ------------------------------------------------------------------------- */

int GameEntity::getX() const {
	return 0;
}

int GameEntity::getY() const {
	return 0;
}

void GameEntity::setX(int x) {}

void GameEntity::setY(int y) {}

/* ------------------------------------------------------------------------- */

EntityType GameEntity::getType() const {
	EntityType *test = new EntityType();

	return *test;
}

void GameEntity::setType(EntityType type) {}

int GameEntity::getHealth() const {
	return 0;
}

void GameEntity::setHealth(int y) {}
