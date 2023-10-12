#include "Cell.hpp"
#include <iostream>
using namespace std;

//Cell::Cell(bool passable) : passable(passable) {}
Cell::Cell(bool passable, pair<int,int> coords) : passable(passable), coords(coords) {}


void Cell::setPassable(bool passable) {
    this->passable = passable;
}

bool Cell::isPassable() const {
    return passable;
}

Cell& Cell::operator=(Cell other) {
    if (this == &other || this->coords.first >= 0) {
        return *this;
    }
    this->coords = other.coords;
    this->passable = other.passable;
    return *this;
}
