#include "Player.hpp"
#include "PlayerController.hpp"
#include "Cell.hpp"
#include "GameField.hpp"
#include "PlayerEvent.hpp"
#include "GameFieldCreator.hpp"

#include <iostream>
using namespace std;
#define FIELD_LVL 2
#define FIELD_SIZE 10
#define FIELD_W 70
#define FIELD_H 70


int main() {

    Player player;
    GameField field(FIELD_W, FIELD_H);
//    GameField field(FIELD_W, FIELD_H, make_pair(0,0), make_pair(6,6));
    PlayerController controller(player, field);

//    cout << field.getEntry().first << " " << field.getEntry().second << " START\n";
//    cout << field.getExit().first << " " << field.getExit().second << " FINISH\n";

    GameFieldCreator creator(field, player, controller);
    creator.createField(FIELD_LVL);

    controller.startGame();

    return 0;
}
