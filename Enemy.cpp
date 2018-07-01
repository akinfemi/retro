#include "Enemy.hpp"

Enemy::Enemy(){}

Enemy::~Enemy(){}

Enemy::Enemy(Enemy const & copy){
    *this = copy;
}

Enemy& Enemy::operator=(Enemy const & rhs){
    this->type = rhs.getType();
    this->bullets_to_kill = rhs.get_bullets_to_kill();
    return (*this);
}

int Enemy::get_bullets_to_kill() const{
    return this->bullets_to_kill;
}

void Enemy::draw(){
    //#TODO
}

void Enemy::shoot(){
    //#TODO
}