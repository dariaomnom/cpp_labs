#include "GameFieldCreator.hpp"

GameFieldCreator::GameFieldCreator(GameField& field, Player& player, PlayerController& controller) : field(field), player(player), controller(controller) {}

void GameFieldCreator::createField(int level) {
//    GameField gameField; // Here you can add logic to create different fields based on the level
    // For example, for level 1 you can create a simple field, for level 2 - a more complex one
//    GameField field = this->field;
    if (level == 1) {
        int density = 5;
        int x = 0; int y = 0;
        for (int i = 0; i < (field.getSize().first * field.getSize().second / density); i++) {
            x = rand() % field.getSize().first; y = rand() % field.getSize().second;
            if (x != field.getEntry().first && y != field.getEntry().second && x != field.getExit().first && y != field.getExit().second)
                field.getCell(x,y).setPassable(false);
        }

    } else if (level == 2) {
        int density = 3;
        int x = 0; int y = 0;
        for (int i = 0; i < (field.getSize().first * field.getSize().second / density); i++) {
            x = rand() % field.getSize().first; y = rand() % field.getSize().second;
            if (x != field.getEntry().first && y != field.getEntry().second && x != field.getExit().first && y != field.getExit().second)
                field.getCell(x,y).setPassable(false);
        }
    }
//    return gameField;
}
