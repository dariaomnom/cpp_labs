#include "PlayerController.hpp"
#include <iostream>
using namespace std;

//PlayerController::PlayerController(Player& player) : player(player) {
//    this->x = 0;
//    this->y = 0;
//}
PlayerController::PlayerController(Player& player, GameField& gameField)
: player(player), gameField(gameField) {
    std::tie(x, y) = gameField.getEntry();
}


void PlayerController::move(Direction direction) {
//    switch (direction) {
//        case Direction::UP:
//            y-1 >= 0 ? y-- : y = 0;
//            break;
//        case Direction::DOWN:
//            y++;
//            break;
//        case Direction::LEFT:
//            x-1 >= 0 ? x-- : x = 0;
//            break;
//        case Direction::RIGHT:
//            x++;
//            break;
//    }
    int newX = this->x, newY = this->y;
    switch (direction) {
        case Direction::UP:    newY--; break;
        case Direction::DOWN:  newY++; break;
        case Direction::LEFT:  newX--; break;
        case Direction::RIGHT: newX++; break;
    }
    if (gameField.getCell(newX, newY).isPassable()) {
        x = newX;
        y = newY;
    }
}

void PlayerController::printPosition() {
    std::cout << "Player is at (" << x << ", " << y << ")\n";
}
