#include "Bullet.hpp"

Bullet::Bullet(){}

Bullet::~Bullet(){}

Bullet::Bullet(Bullet const & copy){
    *this = copy;
}

Bullet& Bullet::operator=(Bullet const & rhs){
    this->type = rhs.getType();
    return (*this);
}

void Bullet::draw(WINDOW *win){
    //#TODO
    (void)win;
}

void Bullet::shoot(WINDOW *win){
    (void)win;
}