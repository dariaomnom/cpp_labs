#include "Cell.hpp"
#include "GameField.hpp"
#include "PlayerEvent.hpp"

using namespace std;
#define MAX_SIZE 101
#define MIN_SIZE 3

GameField::GameField(int width, int height, pair<int,int> entry, pair<int,int> exit) {
    if (width > MIN_SIZE && width < MAX_SIZE && height > MIN_SIZE && height < MAX_SIZE) {
        this->width = width;
        this->height = height;
    } else {
        throw out_of_range("Invalid size of game field");
    }

    cells = new Cell*[height];
    for(int i = 0; i < height; ++i)
        cells[i] = new Cell[width];

    if (entry.first >= 0 && entry.first < width && exit.first >= 0 && exit.first < height) {
        this->entry = entry;
        this->exit = exit;
    } else {
        this->entry = make_pair(0,0);
        this->exit = make_pair(width-1,height-1);
    }
}

GameField::GameField(GameField& other) {
    width = other.width;
    height = other.height;
    entry = other.entry;
    exit = other.exit;

    cells = new Cell*[height];
    for (int i = 0; i < height; ++i) {
        cells[i] = new Cell[width];
    }

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            cells[i][j] = other.cells[i][j];
        }
    }
}

GameField::GameField (GameField&& other) {
    width = other.width;
    height = other.height;
    entry = std::move(other.entry);
    exit = std::move(other.exit);
    cells = other.cells;
    other.cells = nullptr;
}

GameField::~GameField() {
    if (this->cells != nullptr) {
        for (int i = 0; i < height; ++i)
            delete[] cells[i];
        delete[] cells;
    }
}

Cell& GameField::getCell(int x, int y) {
    if(x >= 0 && x < width && y >= 0 && y < height)
        return cells[y][x];
    throw out_of_range("Invalid cell coordinates");
}

//void GameField::randomCells(int density) {
//    int x = 0; int y = 0;
//    for (int i = 0; i < (getSize().first * getSize().second / density); i++) {
//        x = rand() % getSize().first; y = rand() % getSize().second;
//        if (x != getEntry().first && y != getEntry().second && x != getExit().first && y != getExit().second)
//            getCell(x,y).setPassable(false);
//    }
//}

pair<int, int> GameField::getEntry() const { return entry; }
pair<int, int> GameField::getExit() const { return exit; }
pair<int, int> GameField::getSize() const {
    return make_pair(width, height);
}

GameField& GameField::operator=(const GameField& other) {
    if (this != &other) {
        width = other.width;
        height = other.height;
        entry = other.entry;
        exit = other.exit;
        cells = new Cell*[height];
        for (int i = 0; i < height; ++i) {
            cells[i] = new Cell[width];
        }
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                cells[i][j] = other.cells[i][j];
            }
        }
    }
    return *this;
}

GameEvent* GameField::getEvent(int x, int y) {
    return events[x][y];
}

void GameField::addEvent(int x, int y, GameEvent* event) {
    events[x][y] = event;
}