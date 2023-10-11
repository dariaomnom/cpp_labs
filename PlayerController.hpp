#include "Player.hpp"

#ifndef CONTROLLER_H
#define CONTROLLER_H

enum class Direction { UP, DOWN, LEFT, RIGHT };

class PlayerController {
private:
    Player& player;
    int x, y;

public:
    explicit PlayerController(Player& player);

    void move(Direction direction);

    void printPosition();
};
#endif