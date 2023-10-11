#include "Cell.hpp"
#include "GameField.hpp"

GameField::GameField(int width, int height) : width(width), height(height) {
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
void GameField::setEntry(int x, int y) {
    if(x >= 0 && x < width && y >= 0 && y < height)
        entry = {x, y};
    else
        throw out_of_range("Invalid entry coordinates");
}
void GameField::setExit(int x, int y) {
    if(x >= 0 && x < width && y >= 0 && y < height)
        exit = {x, y};
    else
        throw out_of_range("Invalid exit coordinates");
}
pair<int, int> GameField::getEntry() const { return entry; }
pair<int, int> GameField::getExit() const { return exit; }
