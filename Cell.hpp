#ifndef CELL_HPP
#define CELL_HPP
class GameField;
class Cell {
private:
    bool passable;
public:
    explicit Cell(bool passable = true);
    void setPassable(bool passable);
    bool isPassable() const;
    Cell& operator=(Cell other);
    friend GameField;
};
#endif
