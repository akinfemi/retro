#include "Player.hpp"
#include <string>

#define MAX_WIDTH 156
#define MAX_HEIGHT 47

Player::Player(){
    this->alive = true;
    this->type = PLAYER;
    this->num_bullets = 20;
    this->bullets = get_bullets();
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
        if (bullets[i]->alive)
            bullets[i]->draw(win);
    }
}

Bullet ** Player::get_bullets(){
    Bullet ** bullets = new Bullet*[this->get_num_bullets()];
    for (int j = 0; j < this->get_num_bullets(); j++){
        bullets[j] = new Bullet();
    }
    return bullets;
}

int Player::get_num_bullets() const {
    return this->num_bullets;
}

// void Player::add_bullet(Bullet &bullet){
//     Bullet *bullets = this->get_bullets();
//     for (int i = 0; i < get_num_bullets(); i++){
//         if (bullets[i].alive == false){
//             bullets[i].setX(bullet.getX());
//             bullets[i].setY(bullet.getY());

//             bullets[i].setX(50);
//             bullets[i].setY(50);
//             bullets[i].alive = true;
//         }
//     }
// }

void Player::shoot(WINDOW *win){
    //#TODO
    (void)win;
}
