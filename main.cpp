#include "Player.hpp"
#include "PlayerController.hpp"
#include "Cell.hpp"
#include "GameField.hpp"

#include <iostream>
using namespace std;

int main() {
    int field_width = 15; int field_height = 15;

    Player caron;
    GameField home(field_width,field_height);
    PlayerController caron_steps(caron, home);

    int x = 0; int y = 0;
    for (int i = 0; i < (home.getSize().first*home.getSize().second/4); i++) {
        x = rand() % home.getSize().first; y = rand() % home.getSize().second;
        if (x+y != 0)
            home.getCell(x,y).setPassable(false);
    }

    caron_steps.showField();
    char dir;
    while (dir != 'q') {
        cin >> dir;
        switch (dir) {
            case 'w':
                caron_steps.move(Direction::UP);
                caron_steps.showField();
                break;
            case 's':
                caron_steps.move(Direction::DOWN);
                caron_steps.showField();
                break;
            case 'a':
                caron_steps.move(Direction::LEFT);
                caron_steps.showField();
                break;
            case 'd':
                caron_steps.move(Direction::RIGHT);
                caron_steps.showField();
                break;
            case 'p':
                caron.printStats();
                break;
        }
    }
    return 0;
}
