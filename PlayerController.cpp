#include "PlayerController.hpp"
#include <iostream>
using namespace std;
#include "termcolor.hpp"

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
//    int w = gameField.getSize().first;
//    int h = gameField.getSize().second;
//    for (int i = 0; i < h; i++) {
//        for (int j = 0; j < w; j++) {
//            if (gameField.getCell(j, i).isPassable()) {
//                if (x == j && y == i)
//                    cout << "(T-T)";
//                else
//                    cout << " [ ] ";
//            } else {
//                cout << " [#] ";
//            }
//        }
//        cout << "\n";
//    }
//    int x_center = x;
//    int y_center = y;
//    switch (tie(x, y)) {
//        case ()
//    }

    int w = gameField.getSize().first;
    int h = gameField.getSize().second;
    if (w <= 10 && h <= 10) {
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (gameField.getCell(j, i).isPassable()) {
                    if (x == j && y == i)
                        cout << termcolor::blue << "(T-T)" << termcolor::reset;
                    else
                        cout << "  .  ";
                } else {
                    cout << " [#] ";
                }
            }
            cout << "\n";
        }
    } else /*if (x >= 3 && y >= 3 && x < w-3 && y < h-3)*/ {
        int x_center = x;
        int y_center = y;
        if (x < 3) x_center = 3;
        if (y < 3) y_center = 3;
        if (x >= w-3) x_center = w-4;
        if (y >= h-3) y_center = h-4;
        for (int i = y_center-3; i <= y_center+3; i++) {
            for (int j = x_center-3; j <= x_center+3; j++) {
                if (i >= 0 && i < h && j >= 0 && j < w) {
                    if (gameField.getCell(j, i).isPassable()) {
                        if (x == j && y == i)
                            cout << termcolor::blue << "(T-T)" << termcolor::reset;
                        else
                            cout << "  .  ";
                    } else {
                        cout << " [#] ";
                    }
                }
            }
            cout << "\n";
        }
    }
//    else {
//        int x_center = x;
//        int y_center = y;
//        if (x < 3) x_center = 3;
//        if (y < 3) y_center = 3;
//        if (x >= w-3) x_center = w-4;
//        if (y >= h-3) y_center = h-4;
//    }
}