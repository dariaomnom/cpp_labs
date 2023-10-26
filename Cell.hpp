#include "GameEvent.hpp"

#ifndef CELL_HPP
#define CELL_HPP
class GameField;
class Cell {
private:
    bool passable;
    GameEvent* event;
public:
    explicit Cell(bool passable = true, GameEvent* event = nullptr);
    void setPassable(bool passable);
    bool isPassable() const;

    GameEvent* getEvent(); // Get event from cell
    void setEvent(GameEvent* event); // Set event to cell

    Cell& operator=(Cell other);
    friend GameField;
};
#endif
