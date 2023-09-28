#include "PlayerController.hpp"
#include <iostream>
using namespace std;

PlayerController::PlayerController(Player& player, int startX, int startY) {
    this->player = player;
    if (startX >= 0) {
        this->x = startX;
    } else {
        this->x = 0;
    }
    if (startY >= 0) {
        this->y = startY;
    } else {
        this->y = 0;
    }
}

void PlayerController::move(Direction direction) {
    switch (direction) {
        case UP:
            y-1 >= 0 ? y-- : y = 0;
            break;
        case DOWN:
            y++;
            break;
        case LEFT:
            x-1 >= 0 ? x-- : x = 0;
            break;
        case RIGHT:
            x++;
            break;
    }
}

void PlayerController::printPosition() {
    std::cout << "Player is at (" << x << ", " << y << ")\n";
}