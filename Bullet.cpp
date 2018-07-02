#include "Bullet.hpp"

Bullet::Bullet(){
    this->alive = false;
    this->type = BULLET;
}

Bullet::~Bullet(){}

Bullet::Bullet(Bullet const & copy){
    *this = copy;
	this->type = BULLET;
}

Bullet& Bullet::operator=(Bullet const & rhs){
    this->type = rhs.getType();
    return (*this);
}

void Bullet::draw(WINDOW *win){
    int x,y;

    x = this->getX();
    y = this->getY();
	mvwaddch(win, y, x, 'o');
    // wrefresh(win);
}

void Bullet::shoot(WINDOW *win){
    (void)win;
}
