#include "Cell.hpp"
#include <iostream>
using namespace std;

Cell::Cell(bool passable) : passable(passable) {}

void Cell::setPassable(bool passable) {
    this->passable = passable;
}

bool Cell::isPassable() const {
    return passable;
}

Cell& Cell::operator=(Cell other) {
    if (this == &other) return *this;
    this->passable = other.passable;
    return *this;
}
