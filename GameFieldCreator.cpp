#include "GameFieldCreator.hpp"

GameFieldCreator::GameFieldCreator(GameField& field, Player& player, PlayerController& controller) : field(field), player(player), controller(controller) {}

void GameFieldCreator::createField(int level) {
    srand(time(NULL));
    int passable;
    int points;
    int enemies;
    int position;
    int lives;

    if (level == 1) {
        passable = 5;
        points = 2;
        position = 6;
        enemies = 5;
        lives = enemies;
    } else if (level == 2) {
        passable = 3;
        points = 4;
        position = 5;
        enemies = 3;
        lives = enemies;
    } else {
        passable = 4;
        points = 3;
        position = 5;
        enemies = 4;
        lives = enemies;
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
            if (field.getCell(i,j).getEvent()== nullptr && field.getCell(i,j).isPassable()) {

                if ((j-i) % points == 0) {
                    field.getCell(i,j).setEvent(new PointsEvent(player));
                }
                else if ((j-i) % enemies == 0) {
                    field.getCell(i,j).setEvent(new EnemyEvent(player));
                }
                else if ((j-i) % position == 0) {
                    field.getCell(i,j).setEvent(new PositionEvent(player, controller, field));
                }
                else if ((j-i-1) % lives == 0) {
                    field.getCell(i,j).setEvent(new LivesEvent(player));
                }
            }
        }
    }
}
