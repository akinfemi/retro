#include "Player.hpp"

Player::Player(){}

Player::~Player(){}

Player::Player(Player const & copy){
    *this = copy;
}

Player& Player::operator=(Player const & rhs){
    this->type = rhs.getType();
    return (*this);
}

void Player::draw(){
    //#TODO
}

void Player::shoot(){
    //#TODO
}