#include "Player.hpp"
#include <string>

Player::Player(){
    this->alive = true;
    this->type = PLAYER;
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
    //#TODO
    const char * image = " ^ \nxox\n";
    int x,y;

    getyx(win, y, x);
    mvwaddstr(win, y/2, x/2, image);
    wrefresh(win);
}

void Player::shoot(WINDOW *win){
    //#TODO
    (void)win;
}
