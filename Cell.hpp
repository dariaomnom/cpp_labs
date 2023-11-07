#ifndef CELL_HPP
#define CELL_HPP

#include "GameEvent.hpp"

class GameField;
class Cell {
private:
    bool passable;
    GameEvent* event;
public:
    explicit Cell(bool passable = true, GameEvent* event = nullptr);
    void setPassable(bool passable);
    bool isPassable() const;

    GameEvent* getEvent();
    void setEvent(GameEvent* event);

    Cell& operator=(Cell other);
    friend GameField;
};
#endif
