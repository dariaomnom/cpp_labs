#include "PlayerController.hpp"
using namespace std;
#include "lib/termcolor.hpp"
#include "PointsEvent.hpp"
#include "LivesEvent.hpp"
#include "EnemyEvent.hpp"
#include "PositionEvent.hpp"
#include <ncurses.h>
#define REGION_AROUND_PLAYER 10

PlayerController::PlayerController(Player& player, GameField& gameField)
        : player(player), gameField(gameField) {
    tie(x, y) = gameField.getEntry();
}

void PlayerController::move(Direction direction) {
    int newX = x, newY = y;
    switch (direction) {
        case Direction::UP:
            newY-1 >= 0 ? newY-- : newY = 0;
            break;
        case Direction::DOWN:
            newY+1 < gameField.getSize().second ? newY++ : newY = gameField.getSize().second-1;
            break;
        case Direction::LEFT:
            newX-1 >= 0 ? newX-- : newX = 0;
            break;
        case Direction::RIGHT:
            newX+1 < gameField.getSize().first ? newX++ : newX = gameField.getSize().first-1;
            break;
    }
    if (gameField.getCell(newX, newY).isPassable()) {
        x = newX;
        y = newY;
        checkForEvent();
    }
}

void PlayerController::setX(int x) {
    if(x >= 0 && x < gameField.getSize().first)
        this->x = x;
    else if (x < 0)
        this->x = 0;
    else
        this->x = gameField.getSize().first - 1;
}

void PlayerController::setY(int y) {
    if (y >= 0 && y < gameField.getSize().second)
        this->y = y;
    else if (y < 0)
        this->y = 0;
    else
        this->y = gameField.getSize().second - 1;
}

int PlayerController::getX() { return x; }
int PlayerController::getY() { return y; }


void PlayerController::printPosition() {
    cout << "Player is at (" << x << ", " << y << ")\n";
}


void PlayerController::drawGameField() {
//    int width, height;
//    std::tie(width, height) = gameField.getSize();
//
//    // Очищаем экран
    clear();
//
//    for (int y = 0; y < height; ++y) {
//        for (int x = 0; x < width; ++x) {
//            Cell& cell = gameField.getCell(x, y);
//
//            // Выбираем символ для отрисовки в зависимости от состояния ячейки
//            char symbol = ' ';
//            if (!cell.isPassable()) {
//                symbol = '#'; // Символ для непроходимой ячейки
//            }
//            else if (cell.getEvent() != nullptr) {
//                symbol = '*'; // Символ для ячейки с событием
//            }
//            else if () {
//                symbol = '*'; // Символ для ячейки с событием
//            }
//
//            // Отрисовываем символ
//            mvaddch(y, x, symbol);
//        }
//    }
//    cout << "\n";
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_CYAN, COLOR_BLACK);

    int area = REGION_AROUND_PLAYER;

    int w = gameField.getSize().first;
    int h = gameField.getSize().second;
    int x_start = 0;
    int y_start = 0;
    int x_end = 0;
    int y_end = 0;
    if (w <= 10 && h <= 10) {
        x_start = 0;
        y_start = 0;
        x_end = w;
        y_end = h;
    } else {
        int x_center = x;
        int y_center = y;

        if (x_center < area/2) { x_start = 0; x_end = area; }
        else if (x_center >= w - area/2) { x_start = w - area; x_end = w; }
        else { x_start = x_center - area/2; x_end = x_center + area/2+1; }

        if (y_center < area/2) { y_start = 0; y_end = area; }
        else if (y_center >= h - area/2) { y_start = h - area; y_end = h; }
        else { y_start = y_center - area/2; y_end = y_center + area/2+1; }

//        if (x_center < 3) { x_start = 0; x_end = 7; }
//        else if (x_center >= w-3) { x_start = w-7; x_end = w; }
//        else { x_start = x_center - 3; x_end = x_center + 4; }
//
//        if (y_center < 3) { y_start = 0; y_end = 7; }
//        else if (y_center >= h-3) { y_start = h-7; y_end = h; }
//        else { y_start = y_center - 3; y_end = y_center + 4; }
    }
    std::string cell_view;
    int print_pos_y = 0;
//    mvprintw(10, 10, "%s", message.c_str());
    for (int i = y_start; i < y_end; i++) {
        for (int j = x_start; j < x_end; j++) {
            GameEvent* event = gameField.getCell(j, i).getEvent();
            if (gameField.getCell(j, i).isPassable()) {
                if (x == j && y == i)
                    cell_view = "(T-T)";
                else if(dynamic_cast<PointsEvent *>(event)){
                    cell_view = "  $  ";
                }
                else if(dynamic_cast<LivesEvent *>(event)){
                    cell_view = "  +  ";
                }
                else if(dynamic_cast<EnemyEvent *>(event)){
                    cell_view = "  >: ";
                }
                else if(dynamic_cast<PositionEvent *>(event)){
                    cell_view = "  o  ";
                }
                else if(gameField.getExit().first == j && gameField.getExit().second == i){
                    cell_view = " !!! ";
                }
                else
                    cell_view = "  .  ";
            } else {
                cell_view = " [#] ";
            }
//            print_pos_y++;
            if (cell_view == " !!! ")
                attron(COLOR_PAIR(1));
            if (cell_view == "  >: ")
                attron(COLOR_PAIR(2));
            if (cell_view == "(T-T)")
                attron(COLOR_PAIR(3));
            printw("%s", cell_view.c_str());
            if (cell_view == " !!! ")
                attroff(COLOR_PAIR(1));
            if (cell_view == "  >: ")
                attroff(COLOR_PAIR(2));
            if (cell_view == "(T-T)")
                attroff(COLOR_PAIR(3));
        }
        print_pos_y++;
        printw("\n");
    }

    // Обновляем экран
    refresh();
}


void PlayerController::showField() {
    cout << "\n";
    int w = gameField.getSize().first;
    int h = gameField.getSize().second;
    int x_start = 0;
    int y_start = 0;
    int x_end = 0;
    int y_end = 0;
    if (w <= 10 && h <= 10) {
        x_start = 0;
        y_start = 0;
        x_end = w;
        y_end = h;
    } else {
        int x_center = x;
        int y_center = y;

        if (x_center < 3) { x_start = 0; x_end = 7; }
        else if (x_center >= w-3) { x_start = w-7; x_end = w; }
        else { x_start = x_center - 3; x_end = x_center + 4; }

        if (y_center < 3) { y_start = 0; y_end = 7; }
        else if (y_center >= h-3) { y_start = h-7; y_end = h; }
        else { y_start = y_center - 3; y_end = y_center + 4; }
    }
    for (int i = y_start; i < y_end; i++) {
        for (int j = x_start; j < x_end; j++) {
            GameEvent* event = gameField.getCell(j, i).getEvent();
            if (gameField.getCell(j, i).isPassable()) {
                if (x == j && y == i)
                    cout << termcolor::blue << "(T-T)" << termcolor::reset;
                else if(dynamic_cast<PointsEvent *>(event)){
                    cout << "  $  ";
                }
                else if(dynamic_cast<LivesEvent *>(event)){
                    cout << "  +  ";
                }
                else if(dynamic_cast<EnemyEvent *>(event)){
                    cout << termcolor::red << "  >: " << termcolor::reset;
                }
                else if(dynamic_cast<PositionEvent *>(event)){
                    cout << "  o  ";
                }
                else if(gameField.getExit().first == j && gameField.getExit().second == i){
                    cout << termcolor::green << " !!! " << termcolor::reset;
                }
                else
                    cout << "  .  ";
            } else {
                cout << " [#] ";
            }
        }
        cout << "\n";
    }
}

void PlayerController::startGame() {
    this->showField();
    char dir;
    while (dir != 'q') {
        cin >> dir;
        switch (dir) {
            case 'w':
                this->move(Direction::UP);
                this->showField();
                break;
            case 's':
                this->move(Direction::DOWN);
                this->showField();
                break;
            case 'a':
                this->move(Direction::LEFT);
                this->showField();
                break;
            case 'd':
                this->move(Direction::RIGHT);
                this->showField();
                break;
            case 'p':
                player.printStats();
                break;
        }
    }
}

void PlayerController::checkForEvent() {
    GameEvent* event = gameField.getCell(x,y).getEvent();
    if (event) {
        event->triggerEvent();
        gameField.getCell(x, y).setEvent(nullptr);
    }
}