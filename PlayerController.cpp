#include "PlayerController.hpp"
using namespace std;
#include "lib/termcolor.hpp"

PlayerController::PlayerController(Player& player, GameField& gameField)
        : player(player), gameField(gameField) {
    tie(x, y) = gameField.getEntry();
}

void PlayerController::move(Direction direction) {
    int newX = x, newY = y;
    switch (direction) {
        case Direction::UP:
            newY-1 >= 0 ? newY-- : newY = 0;
            break;
        case Direction::DOWN:
            newY+1 < gameField.getSize().second ? newY++ : newY = gameField.getSize().second-1;
            break;
        case Direction::LEFT:
            newX-1 >= 0 ? newX-- : newX = 0;
            break;
        case Direction::RIGHT:
            newX+1 < gameField.getSize().first ? newX++ : newX = gameField.getSize().first-1;
            break;
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
    int x_start = 0;
    int y_start = 0;
    int x_end = 0;
    int y_end = 0;
    if (w <= 10 && h <= 10) {
        x_start = 0;
        y_start = 0;
        x_end = w;
        y_end = h;
    } else {
        int x_center = x;
        int y_center = y;

        if (x_center < 3) { x_start = 0; x_end = 7; }
        else if (x_center >= w-3) { x_start = w-7; x_end = w; }
        else { x_start = x_center - 3; x_end = x_center + 4; }

        if (y_center < 3) { y_start = 0; y_end = 7; }
        else if (y_center >= h-3) { y_start = h-7; y_end = h; }
        else { y_start = y_center - 3; y_end = y_center + 4; }
    }
    for (int i = y_start; i < y_end; i++) {
        for (int j = x_start; j < x_end; j++) {
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
}

void PlayerController::startGame() {
    this->showField();
    char dir;
    while (dir != 'q') {
        cin >> dir;
        switch (dir) {
            case 'w':
                this->move(Direction::UP);
                this->showField();
                break;
            case 's':
                this->move(Direction::DOWN);
                this->showField();
                break;
            case 'a':
                this->move(Direction::LEFT);
                this->showField();
                break;
            case 'd':
                this->move(Direction::RIGHT);
                this->showField();
                break;
            case 'p':
                player.printStats();
                break;
        }
    }
}

void PlayerController::checkForEvent() {
    GameEvent* event = gameField.getEvent(x, y);
    if (event) {
        event->triggerEvent();
    }
}