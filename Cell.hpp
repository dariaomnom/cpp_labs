#ifndef LABS_CELL_HPP
#define LABS_CELL_HPP
#include <iostream>
class GameField;
class Cell {
private:
    bool passable;
    std::pair<int,int> coords;
public:
    explicit Cell(bool passable = true, std::pair<int,int> coords = std::make_pair(-1,-1));
    void setPassable(bool passable);
    bool isPassable() const;
    Cell& operator=(Cell other);
    friend GameField;
};
#endif
