#include "Player.hpp"

#ifndef CONTROLLER_H
#define CONTROLLER_H

enum Direction { UP, DOWN, LEFT, RIGHT };

class PlayerController {
private:
    Player& player;
    int x, y;

public:
    explicit PlayerController(Player& player, int start_x = 0, int start_y = 0);

    void move(Direction direction);

    void printPosition();
};
#endif