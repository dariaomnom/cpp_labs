#include "Cell.hpp"
#include "GameField.hpp"

GameField::GameField(int width, int height) {
    if (width > 3 && width < 101 && height > 3 && height < 101) {
        this->width = width;
        this->height = height;
    } else {
        throw out_of_range("Invalid size of game field");
    }

    cells = new Cell*[height];
    for(int i = 0; i < height; ++i)
        cells[i] = new Cell[width];

    entry = make_pair(0,0);
    exit = make_pair(width-1,height-1);
}
GameField::~GameField() {
    for(int i = 0; i < height; ++i)
        delete [] cells[i];
    delete [] cells;
}

Cell& GameField::getCell(int x, int y) {
    if(x >= 0 && x < width && y >= 0 && y < height)
        return cells[y][x];
    throw out_of_range("Invalid cell coordinates");
}

void GameField::randomCells(int density) {
    int x = 0; int y = 0;
    for (int i = 0; i < (getSize().first * getSize().second / density); i++) {
        x = rand() % getSize().first; y = rand() % getSize().second;
        if (x+y != 0)
            getCell(x,y).setPassable(false);
    }
}

pair<int, int> GameField::getEntry() const { return entry; }
pair<int, int> GameField::getExit() const { return exit; }
pair<int, int> GameField::getSize() const {
    return make_pair(width, height);
}
