#include "Player.hpp"
#include "GameField.hpp"
#include "GameEvent.hpp"

#ifndef CONTROLLER_H
#define CONTROLLER_H

enum class Direction { UP, DOWN, LEFT, RIGHT };

class PlayerController {
private:
    Player& player;
    GameField& gameField;
    int x, y;

public:
    explicit PlayerController(Player& player, GameField& gameField);
    void move(Direction direction);
    void checkForEvent();
    void printPosition();
    void showField();
    void startGame();
};
#endif