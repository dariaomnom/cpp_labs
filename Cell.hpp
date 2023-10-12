#ifndef LABS_CELL_HPP
#define LABS_CELL_HPP
class Cell {
private:
    bool passable;
public:
    explicit Cell(bool passable = true);
    void setPassable(bool passable);
    bool isPassable() const;
};
#endif
