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
    explicit GameField(int width = 10, int height = 10);
    ~GameField();
    Cell& getCell(int x, int y);
    pair<int, int> getEntry() const;
    pair<int, int> getExit() const;
    pair<int, int> getSize() const;
};
#endif