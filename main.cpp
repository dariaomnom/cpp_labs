#include "Player.hpp"
#include "PlayerController.hpp"
#include "Cell.hpp"
#include "GameField.hpp"

#include <iostream>
using namespace std;

int main() {
    int field_width = 10; int field_height = 10;

    Player caron;
    GameField home(field_width,field_height);
    PlayerController caron_steps(caron, home);

    int x = 0; int y = 0;
    for (int i = 0; i < (field_height*field_width/3); i++) {
        x = rand() % field_width; y = rand() % field_height;
        if (x+y != 0)
            home.getCell(x,y).setPassable(false);
    }

    caron_steps.move(Direction::RIGHT);
    caron_steps.move(Direction::DOWN);


    caron_steps.showField();
    return 0;
}
