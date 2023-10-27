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
        points = 3;
        position = 6;
        enemies = 5;
//        enemies = field.getSize().first * field.getSize().second / 10 - 1;
//        if (enemies == points || enemies == position) enemies += 1;
        lives = enemies * 2;
//        if (lives == points || lives == position) lives += 1;
    } else if (level == 2) {
        passable = 3;
        points = 2;
        position = 5;
        enemies = 3;
//        enemies = field.getSize().first * field.getSize().second / 15 - 1;
//        if (enemies == points || enemies == position)
//            enemies -= 1;
        lives = enemies * 2;
//        if (lives == points || lives == position) lives += 1;
    } else {
        passable = 4;
        points = 3;
        position = 5;
        enemies = 4;
//        enemies = field.getSize().first * field.getSize().first / 10 - 2;
//        if (enemies == points || enemies == position)
//            enemies -= 1;
        lives = enemies * 3;
//        if (lives == points || lives == position) lives += 1;
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

//                if (((j+1) * field.getSize().first + i + 1) % points == 0)
                if ((j-i) % points == 0)
                {
                    field.getCell(i,j).setEvent(new PointsEvent(player));
                }
                else if ((j-i) % enemies == 0)
//                    if (((j+1) * field.getSize().first + i + 1) % enemies == 0)
                {
                    field.getCell(i,j).setEvent(new EnemyEvent(player));
                }
                else if ((j-i) % position == 0)
//                    if (((j+1) * field.getSize().first + i + 1) % position == 0)
                {
                    field.getCell(i,j).setEvent(new PositionEvent(player, controller, field));
                }
                else if ((j-i) % lives == 0)
//                    if (((j+1) * field.getSize().first + i + 1) % lives == 0)
                {
                    field.getCell(i,j).setEvent(new LivesEvent(player));
                }
            }
        }
    }
}
