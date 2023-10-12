#include "Cell.hpp"

Cell::Cell(bool passable) : passable(passable) {}

void Cell::setPassable(bool passable) {
    this->passable = passable;
}

bool Cell::isPassable() const {
    return passable;
}

