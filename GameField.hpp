#ifndef GAMEFIELD_HPP
#define GAMEFIELD_HPP
#include <iostream>
using namespace std;
#include "Cell.hpp"

class GameField {
private:
    int width, height;
    Cell** cells;
    pair<int, int> entry, exit;
public:
    GameField(int width = 10, int height = 10);
    ~GameField();
    Cell& getCell(int x, int y);
    void setEntry(int x, int y);
    void setExit(int x, int y);
    pair<int, int> getEntry() const;
    pair<int, int> getExit() const;

//    void showField();
};
#endif
