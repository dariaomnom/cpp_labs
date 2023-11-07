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
        passable = 4;
        points = 4;
        position = 10;
        enemies = 7;
        lives = 9;
    } else if (level == 2) {
        passable = 3;
        points = 4;
        position = 10;
        enemies = 4;
        lives = 8;

    } else {
        passable = 4;
        points = 4;
        position = 10;
        enemies = 5;
        lives = 8;
    }

    points = (field.getSize().first * field.getSize().second) / points;
    position = field.getSize().first * field.getSize().second / position;
    enemies = field.getSize().first * field.getSize().second / enemies;
    lives = field.getSize().first * field.getSize().second / lives;
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

        // rand walls
        for (int i = 0; i < (field.getSize().first * field.getSize().second / passable); i++) {
            x = rand() % field.getSize().first;
            y = rand() % field.getSize().second;
            if (!((x == field.getEntry().first && y == field.getEntry().second) || (x == field.getExit().first &&
                y == field.getExit().second))
//                && (x >= 0 && x < width && y >= 0 && y < height)
                ) {
//                cout << x << " X " << y << " Y\n";
//                if (x >= 0 && x < width && y >= 0 && y < height && field.getCell(x, y).isPassable())
                    field.getCell(x, y).setPassable(false);
//                else
//                    i--;
            } else i--;
        }
        cout << "Generated field without events:";
        controller.showField();
    } while (!checkPath(field));


    while (poi < points || pos < position || en < enemies || li < lives) {

        // points
        x = rand() % field.getSize().first;
        y = rand() % field.getSize().second;
        if (checkRandomCords(field, x, y)
            && (poi < points)) {
            field.getCell(x, y).setEvent(new PointsEvent(player));
            poi++;
        }
        // lives
        x = rand() % field.getSize().first;
        y = rand() % field.getSize().second;
        if (checkRandomCords(field, x, y)
            && (li < lives)) {
            field.getCell(x, y).setEvent(new LivesEvent(player));
            li++;
        }
        // position
        x = rand() % field.getSize().first;
        y = rand() % field.getSize().second;
        if (checkRandomCords(field, x, y)
            && (pos < position)) {
            field.getCell(x, y).setEvent(new PositionEvent(player, controller, field));
            pos++;
        }
        // enemies
        x = rand() % field.getSize().first;
        y = rand() % field.getSize().second;
        if (checkRandomCords(field, x, y)
            && (en < enemies)) {
            field.getCell(x, y).setEvent(new EnemyEvent(player));
            en++;
        }

//        cout << "poi " << poi << " " << points << " pos " << pos << " " << position << " en " << en << " " << enemies << " li " << li << " " << lives << "\n";
        controller.showField();
    }

    if (player.getLives() > enemies) {
        player.setLives(enemies);
    }

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
bool GameFieldCreator::checkPath(GameField& field) {
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
        return true;
    else
        return false;
}

bool GameFieldCreator::checkRandomCords(GameField& field, int x, int y) {
    GameEvent* event = field.getCell(x, y).getEvent();
    if (event == nullptr && field.getCell(x,y).isPassable()
     && (!((x == field.getEntry().first && y == field.getEntry().second) ||
           (x == field.getExit().first && y == field.getExit().second)))
//     && (dynamic_cast<GameEvent *>(event) == nullptr)
//     && (poi <= points)
     )
        return true;
    return false;
}