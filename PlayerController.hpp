#include "Player.hpp"
#include "GameField.hpp"
#include "PlayerEvent.hpp"


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

    void setX(int x);
    void setY(int y);
    int getX();
    int getY();

    void checkForEvent();
    void printPosition();

    void drawGameField();
    void showField();

    void startGame();
};
#endif