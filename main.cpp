#include "Player.hpp"
#include "PlayerController.hpp"
#include "Cell.hpp"
#include "GameField.hpp"
#include "PlayerEvent.hpp"
#include "GameFieldCreator.hpp"

#include <iostream>
using namespace std;

int main() {
    int field_width = 15; int field_height = 15;

    Player player;
    GameField field(field_width,field_height);
    PlayerController controller(player, field);

    cout << field.getEntry().first << " " << field.getEntry().second << " START\n";
    cout << field.getExit().first << " " << field.getExit().second << " FINISH\n";

//    field.randomCells(3);
    GameFieldCreator creator(field, player, controller);
    creator.createField(2);

    controller.startGame();

    return 0;
}
