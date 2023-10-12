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
pair<int, int> GameField::getEntry() const { return entry; }
pair<int, int> GameField::getExit() const { return exit; }
pair<int, int> GameField::getSize() const {
    return make_pair(width, height);
}
