#include "PlayerController.hpp"
#include <iostream>
using namespace std;

PlayerController::PlayerController(Player& player, GameField& gameField)
: player(player), gameField(gameField) {
    tie(x, y) = gameField.getEntry();
}


void PlayerController::move(Direction direction) {
    int newX = this->x, newY = this->y;
    switch (direction) {
        case Direction::UP:    newY-1 >= 0 ? newY-- : newY = 0; break;
        case Direction::DOWN:  newY+1 < gameField.getSize().second ? newY++ : newY = gameField.getSize().second-1; break;
        case Direction::LEFT:  newX-1 >= 0 ? newX-- : newX = 0; break;
        case Direction::RIGHT: newX+1 < gameField.getSize().first ? newX++ : newX = gameField.getSize().first-1; break;
    }
    if (gameField.getCell(newX, newY).isPassable()) {
        x = newX;
        y = newY;
    }
}

void PlayerController::printPosition() {
    cout << "Player is at (" << x << ", " << y << ")\n";
}

void PlayerController::showField() {
    int w = gameField.getSize().first;
    int h = gameField.getSize().second;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (gameField.getCell(j, i).isPassable()) {
                if (x == j && y == i)
                    cout << "(T-T)";
                else
                    cout << " [ ] ";
            } else {
                cout << " [#] ";
            }
        }
        cout << "\n";
    }
}