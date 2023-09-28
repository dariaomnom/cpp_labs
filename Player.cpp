#include "Player.hpp"

Player::Player(int lives, int points) {
    setLife(lives);
    setPoints(points);
}

void Player::addPoints(int points) {
    setPoints(getPoints() + points);
}

void Player::addLife(int lives) {
    setLife(getLives()+lives);
}

void Player::loseLife() {
    setLife(getLives()-1);
}

void Player::levelUp() {
    this->level += 1;
}

void Player::setLife(int lives) {
    if (lives < 0) {
        this->lives = 0;
    } else if (lives <= 10) {
        this->lives = lives;
    } else this->lives = 10;
}

void Player::setPoints(int points) {
    if (points < 0) this->points = 0;
    else if (points > 1000) this->points = 1000;
    else this->points = points;
    if (this->points >= 100) {
        levelUp();
        this->points = 0;
    }
}

int Player::getLives() { return this->lives; }
int Player::getPoints() { return this->points; }
int Player::getLevel() { return this->level; }
