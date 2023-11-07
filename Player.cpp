#include "Player.hpp"
#include <iostream>
using namespace std;
#include "lib/termcolor.hpp"

Player::Player(int lives, int points) {
    setLives(lives);
    setPoints(points);
    setLevel(1);
}

void Player::addLives(int lives) {
    setLives(this->lives + lives);
}

void Player::loseLives(int lives) {
    setLives(this->lives - lives);
    if (this->lives == 0) {
        cout << termcolor::red << "Game over\n" << termcolor::reset;
        printStats();
        exit(0);
    }
}

void Player::addPoints(int points) {
    setPoints(this->points + points);
}

void Player::levelUp() {
    setLevel(this->level + 1);
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

int Player::getLives() const { return lives; }
int Player::getPoints() const { return points; }
int Player::getLevel() const { return level; }

void Player::printStats() {
    cout << "STATS\n";
    cout << "Lives: " << getLives() << "\n";
    cout << "Points: " << getPoints() << "\n";
    cout << "Level: " << getLevel() << "\n";
}
