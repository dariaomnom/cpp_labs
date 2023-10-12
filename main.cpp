#include "Player.hpp"
#include "PlayerController.hpp"
#include "Cell.hpp"
#include "GameField.hpp"

#include <iostream>
using namespace std;

int main() {
    int field_width = 15; int field_height = 15;

    Player player;
    GameField field(field_width,field_height);
    PlayerController controller(player, field);

    field.randomCells(3);
//    controller.startGame();

//    cout << field.getEntry().first << " " << field.getEntry().second << "\n";
//    cout << field.getExit().first << " " << field.getExit().second << "\n";

    return 0;
}
