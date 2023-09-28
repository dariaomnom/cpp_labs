#include "Player.hpp"
#include <iostream>
using namespace std;


//Player::Player(int lives, int points) : lives(lives), points(points) {}
Player::Player(int lives, int points) {
    if (lives < 0) this->lives = 0;
    else if (lives > 10) this->lives = 10;
    else this->lives = lives;

    if (points < 0) this->points = 0;
    else if (points > 1000) this->points = 1000;
    else this->points = points;
}

void Player::addPoints(int points) {
//    if (points >= 0) this->points += points;
    setPoints(getPoints() + points);
//    if (this->points < 0) this->points = 0;
}

void Player::loseLife() {
//    this->lives--;
//    if (this->lives < 0) this->lives = 0;
    setLife(getLives()-1);
}

void Player::addLife(int lives) {
//    if (lives >= 0) this->lives += lives; // no negative lives
//    if (this->lives > 10) this->lives = 10; // max 10 lives
    setLife(getLives()+lives);
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
