#include "Player.hpp"
#include <string>

#define MAX_WIDTH 156
#define MAX_HEIGHT 47

Player::Player(){
    this->alive = true;
    this->type = PLAYER;
    this->num_bullets = 80;
    add_bullets();
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

    //bullets
    for (int i = 0; i < this->get_num_bullets(); i++){
        if (bullets[i]->alive){
            bullets[i]->move_entity(UP, NORMAL);
            bullets[i]->draw(win);
            if (bullets[i]->getY() < 0){
                bullets[i]->alive = false;
            }
        }
    }
}

void Player::add_bullets(){
    Bullet ** bullets = new Bullet*[this->get_num_bullets()];
    for (int j = 0; j < this->get_num_bullets(); j++){
        bullets[j] = new Bullet();
    }
    this->bullets = bullets;;
}

Bullet **Player::get_bullets(){
    return this->bullets;
}

int Player::get_num_bullets() const {
    return this->num_bullets;
}

void Player::shoot(WINDOW *win){
    //#TODO
    Bullet **bullets = this->get_bullets();
    if (!bullets || !*bullets){
        return ;
    }
    for (int i = 0; i < this->get_num_bullets(); i++){
        if (bullets[i]->alive == false){
            bullets[i]->alive = true;
            bullets[i]->setX(this->getX());
            bullets[i]->setY(this->getY());
        }
    }
    (void)win;
}
