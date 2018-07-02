#include "Enemy.hpp"

Enemy::Enemy(){
    this->alive = true;
    this->setHealth(1);
	this->type = ENEMY;
}

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

void Enemy::draw(WINDOW *win){
    //#TODO
    const char * top = "xox";
    const char * bottom = "@@@";
    int x,y;

    x = this->getX();
    y = this->getY();
    // printw("%i, %i", x,y);
    for (int i = 0; i < 3; i ++){
        mvwaddch(win,y, x-1, top[i]);
        x++;
    }
    x = this->getX();
    y = this->getY();
    for (int i = 0; i < 3; i ++){
        mvwaddch(win,y+1, x-1,bottom[i]);
        x++;
    }
}

void Enemy::shoot(WINDOW *win){
    //#TODO
    (void)win;
}
