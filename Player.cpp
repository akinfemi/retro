#include "Player.hpp"
#include <string>

#define MAX_WIDTH 156
#define MAX_HEIGHT 47

Player::Player(){
    this->alive = true;
    this->type = PLAYER;
    setX(MAX_WIDTH / 2);
    setY(MAX_HEIGHT / 2);
}

Player::~Player(){}

Player::Player(Player const & copy){
    *this = copy;
}

Player& Player::operator=(Player const & rhs){
    this->type = rhs.getType();
    return (*this);
}

void Player::draw(WINDOW *win){
    const char * top = "_^_";
    const char *bottom = "xox";
    int x,y;

    x = this->getX();
    y = this->getY();
    for (int i = 0; i < 3; i ++){
        mvwaddch(win,y, x-1,top[i]);
        x++;
    }
    x = this->getX();
    y = this->getY();
    for (int i = 0; i < 3; i ++){
        mvwaddch(win,y+1, x-1, bottom[i]);
        x++;
    }
}

void Player::shoot(WINDOW *win){
    //#TODO
    (void)win;
}
