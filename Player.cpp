#include "Player.hpp"

Player::Player(){

}

Player::~Player(){

}

Player::Player(Player const &copy){
}

Player& Player::operator=(Player const &rhs){
	(void)rhs;
	return *this;
}

void GameEntity::move() {}

void GameEntity::shoot() {}
