#include "PlayerController.hpp"
#include <iostream>
using namespace std;

PlayerController::PlayerController(Player& player, int startX, int startY) : player(player), x(startX), y(startY) {}

void PlayerController::move(Direction direction) {
    switch (direction) {
        case UP: y-1 >= 0 ? y-- : y = 0; break;
        case DOWN: y++; break;
        case LEFT: x-1 >= 0 ? x-- : x = 0; break;
        case RIGHT: x++; break;
    }
}

void PlayerController::printPosition() {
    std::cout << "Player is at (" << x << ", " << y << ")\n";
}