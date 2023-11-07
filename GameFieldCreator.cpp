#include "GameFieldCreator.hpp"

GameFieldCreator::GameFieldCreator(GameField& field, Player& player, PlayerController& controller) : field(field), player(player), controller(controller) {}

void GameFieldCreator::createField(int level) {
    srand(time(NULL));
    int passable;
    int points;
    int enemies;
    int position;
    int lives;

    // choose level
    if (level == 1) {
        passable = 5;
//        points = 2;
        points = 4;
//        position = 6;
        position = 12;
//        enemies = 5;
        enemies = 10;
        lives = enemies;
    } else if (level == 2) {
        passable = 3;
//        points = 4;
        points = 4;
//        position = 5;
        position = 8;
//        enemies = 3;
        enemies = 6;
        lives = enemies;

    } else {
        passable = 4;
//        points = 3;
        points = 6;
//        position = 5;
        position = 10;
//        enemies = 4;
        enemies = 8;
        lives = enemies;
    }

    points = (field.getSize().first * field.getSize().second) / points;
    position = field.getSize().first * field.getSize().second / position;
    enemies = field.getSize().first * field.getSize().second / enemies;
    lives = enemies;
    int poi = 0; int pos = 0; int en = 0; int li = 0;
    int x = 0;
    int y = 0;

    int randomizer = 0;
    int width = field.getEntry().first;
    int height = field.getEntry().second;
    bool passable_path = false;

    do {
//        if (checkPath(field) != 0) {
            for (int j = 0; j < field.getSize().second; j++) {
                for (int i = 0; i < field.getSize().first; i++) {
                    field.getCell(i, j).setPassable(true);
                }
            }
//        }
        cout << "pupupu\n";

        // rand walls
        for (int i = 0; i < (field.getSize().first * field.getSize().second / passable); i++) {
            x = (rand()) % field.getSize().first;
            y = (rand()) % field.getSize().second;
//            if ((x != field.getEntry().first || y != field.getEntry().second) && (x != field.getExit().first ||
//                y != field.getExit().second))
//                field.getCell(x, y).setPassable(false);
            if (!((x == field.getEntry().first && y == field.getEntry().second) || (x == field.getExit().first &&
                y == field.getExit().second))) {
//                cout << x << " X " << y << " Y\n";
//                if (x >= 0 && x < width && y >= 0 && y < height)
                    field.getCell(x, y).setPassable(false);
            }
        }
        controller.showField();
    } while (checkPath(field) != 0);


    for (int j = 0; j < field.getSize().second; j++) {
        for (int i = 0; i < field.getSize().first; i++) {

            x = rand() % field.getSize().first;
            y = rand() % field.getSize().second;
            GameEvent* event = field.getCell(x, y).getEvent();

            if (event == nullptr && field.getCell(x,y).isPassable()
                && (!((x == field.getEntry().first && y == field.getEntry().second) ||
                      (x == field.getExit().first && y == field.getExit().second)))) {
//                x = rand() % field.getSize().first;
//                y = rand() % field.getSize().second;
                if (dynamic_cast<GameEvent *>(event) == nullptr &&
                        (!((x == field.getEntry().first && y == field.getEntry().second) ||
                        (x == field.getExit().first && y == field.getExit().second)))
                ) {
                    if (poi <= points) {
//                        x = rand() % field.getSize().first;
//                        y = rand() % field.getSize().second;
                        field.getCell(x, y).setEvent(new PointsEvent(player));
                        poi++;
                    }

                    if (li <= lives) {
//                        x = rand() % field.getSize().first;
//                        y = rand() % field.getSize().second;
                        field.getCell(x, y).setEvent(new LivesEvent(player));
                        li++;
                    }
                }
            } else {
                i--;
                j--;
            }
        }
    }

    // set events
//    for (int j = 0; j < field.getSize().second; j++) {
//        for (int i = 0; i < field.getSize().first; i++) {
//            if (field.getCell(i,j).getEvent()== nullptr && field.getCell(i,j).isPassable()
//            && (!((i == field.getEntry().first && j == field.getEntry().second) ||
//            (i == field.getExit().first && j == field.getExit().second)))) {
//
//                if ((j-i) % points == 0) {
//                    field.getCell(i,j).setEvent(new PointsEvent(player));
//                }
//                else if ((j-i) % enemies == 0) {
//                    field.getCell(i,j).setEvent(new EnemyEvent(player));
//                }
//                else if ((j-i) % position == 0) {
//                    field.getCell(i,j).setEvent(new PositionEvent(player, controller, field));
//                }
//                else if ((j-i-2) % lives == 0) {
//                    field.getCell(i,j).setEvent(new LivesEvent(player));
//                }
//            }
//        }
//    }

}


// Функция для проверки, является ли данная позиция допустимой
bool GameFieldCreator::isSafe(GameField& field, bool **visited, int x, int y, int width, int height) {
    if(x >= 0 && x < width && y >= 0 && y < height && field.getCell(x,y).isPassable()/*maze[x][y] == '.'*/ && !visited[x][y])
        return true;
    return false;
}

// Функция для поиска пути в лабиринте
bool GameFieldCreator::findPath(GameField& field, bool **visited, int x, int y, int exitX, int exitY, int width, int height) {
    if(x == exitX && y == exitY)
        return true;

    if(isSafe(field, visited, x, y, width, height)) {
        visited[x][y] = true;

        if(findPath(field, visited, x+1, y, exitX, exitY, width, height))
            return true;
        if(findPath(field, visited, x, y+1, exitX, exitY, width, height))
            return true;
        if(findPath(field, visited, x-1, y, exitX, exitY, width, height))
            return true;
        if(findPath(field, visited, x, y-1, exitX, exitY, width, height))
            return true;
    }

    return false;
}

// Функция, которую вы вызываете
int GameFieldCreator::checkPath(GameField& field) {
    int width = field.getSize().first;
    int height = field.getSize().second;
    // Создаем массив для отслеживания посещенных ячеек
    bool **visited = new bool*[width];
    for(int i = 0; i < width; i++) {
        visited[i] = new bool[height];
        for(int j = 0; j < height; j++)
            visited[i][j] = false;
    }

    if(findPath(field, visited, field.getEntry().first, field.getEntry().second, field.getExit().first, field.getExit().second, field.getSize().first, field.getSize().second))
        return 0;
    else
        return 1;
}