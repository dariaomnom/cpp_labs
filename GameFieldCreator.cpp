#include "GameFieldCreator.hpp"

GameFieldCreator::GameFieldCreator(GameField& field, Player& player, PlayerController& controller) : field(field), player(player), controller(controller) {}

void GameFieldCreator::createField(int level) {
    srand(time(NULL));
    int passable;
    int points;
    int enemies;

    if (level == 1) {
        passable = 5;
        points = 3;
        enemies = 5;
    } else if (level == 2) {
        passable = 3;
        points = 3;
        enemies = 3;
    } else {
        passable = 4;
        points = 4;
        enemies = 4;
    }

    int x = 0; int y = 0;
    for (int i = 0; i < (field.getSize().first * field.getSize().second / passable); i++) {
        x = rand() % field.getSize().first;
        y = rand() % field.getSize().second;
        if (x != field.getEntry().first && y != field.getEntry().second && x != field.getExit().first && y != field.getExit().second)
            field.getCell(x,y).setPassable(false);
    }
    for (int j = 0; j < field.getSize().second; j++) {
        for (int i = 0; i < field.getSize().first; i++) {
            if (!field.getCell(i,j).getEvent() && field.getCell(i,j).isPassable()) {
                if ((j * field.getSize().first + i + 1) % points == 0) {
//                    GameEvent* event = PointsEvent(player);
                    field.getCell(i,j).setEvent(new PointsEvent(player));
                    int a = 0;
                }
            }
        }
    }
}
