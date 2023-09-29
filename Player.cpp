#include "Player.hpp"
#include <iostream>
using namespace std;

Player::Player(int lives, int points) {
    setLives(lives);
    setPoints(points);
    setLevel(1);
}

void Player::addLives(int lives) {
    setLives(getLives() + lives);
}

void Player::loseLives(int lives) {
    setLives(getLives() - lives);
}

void Player::addPoints(int points) {
    setPoints(getPoints() + points);
}

void Player::levelUp() {
    setLevel(getLevel()+1);
}

void Player::setLives(int lives) {
    if (lives < 0) {
        this->lives = 0;
    } else if (lives <= 10) {
        this->lives = lives;
    } else this->lives = 10;
}

void Player::setPoints(int points) {
    if (points < 0) {
        this->points = 0;
    }
    else if (points > 1000) {
        this->points = 1000;
    }
    else {
        this->points = points;
    }
    setLevel(this->points / 100 + 1);
}

void Player::setLevel(int level) {
    if (level >= 1) {
        this->level = level;
    }
}

int Player::getLives() { return this->lives; }
int Player::getPoints() { return this->points; }
int Player::getLevel() { return this->level; }

void Player::printLives() {
    cout << "Player has " << this->getLives() << " lives\n";
}

void Player::printPoints() {
    cout << "Player has " << this->getPoints() << " points\n";
}

void Player::printLevel() {
    cout << "Player has level " << this->getLevel() << "\n";
}

void Player::printStats() {
    cout << "Lives: " << this->getLives() << "\n";
    cout << "Points: " << this->getPoints() << "\n";
    cout << "Level: " << this->getLevel() << "\n";
}
