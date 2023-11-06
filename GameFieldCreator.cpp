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

    // rand walls
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
                else if ((j-i-2) % lives == 0) {
                    field.getCell(i,j).setEvent(new LivesEvent(player));
                }
            }
        }
    }
}






//int GameFieldCreator::checkMaze() {
//    void mazeTraverse(char lab[][column], int rw, int cl, int x, int y, int steep)
//    {
////        printSteep(lab, rw, cl, x, y);
//
//        if(lab[x][y] == '.' && (x == 4 && y == 11))
//            return;
//            // steep - 1 - движение вниз и проверка вправо на наличие стены
//        else if(steep == 1){
//            if(lab[x + 1][y] == '.' && lab[x + 1][y - 1] == '#'){ // вперёд - справа стена
//                x++;
//                steep = 1;
//            }
//            else if(lab[x + 1][y] == '.' && lab[x + 1][y - 1] == '.'){ // угол - поворот направо
//                x++;
//                steep = 2;
//            }
//            else if(lab[x + 1][y] == '#' && lab[x + 1][y - 1] == '#') // глухой угол - поворот налево
//                steep = 4;
//        }
//            // steep - 2 - движение влево и проверка вправо вверх на наличие стены
//        else if(steep == 2){
//            if(lab[x][y - 1] == '.' && lab[x - 1][y - 1] == '#'){
//                y--;
//                steep = 2;
//            }
//            else if(lab[x][y - 1] == '.' && lab[x - 1][y - 1] == '.'){
//                y--;
//                steep = 3;
//            }
//            else if(lab[x][y - 1] == '#' && lab[x - 1][y - 1] == '#')
//                steep = 1;
//        }
//            // steep - 3 - движение вверх и проверка вправо вверх на наличие стены
//        else if(steep == 3){
//            if(lab[x - 1][y] == '.' && lab[x - 1][y + 1] == '#'){
//                x--;
//                steep = 3;
//            }
//            else if(lab[x - 1][y] == '.' && lab[x - 1][y + 1] == '.'){
//                x--;
//                steep = 4;
//            }
//            else if(lab[x - 1][y] == '#' && lab[x - 1][y + 1] == '#')
//                steep = 2;
//        }
//            // steep - 4 - движение вправо и проверка вправо вниз на наличие стены
//        else if(steep == 4){
//            if(lab[x][y + 1] == '.' && lab[x + 1][y + 1] == '#'){
//                y++;
//                steep = 4;
//            }
//            else if(lab[x][y + 1] == '.' && lab[x + 1][y + 1] == '.'){
//                y++;
//                steep = 1;
//            }
//            else if(lab[x][y + 1] == '#' && lab[x + 1][y + 1] == '#')
//                steep = 3;
//        }
//        mazeTraverse(lab, rw, cl, x, y, steep);
//    }
//}
