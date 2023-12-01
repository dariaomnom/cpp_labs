#include "Cell.hpp"
//#include "Events/PlayerEvent.hpp"
#include <iostream>
using namespace std;

Cell::Cell(bool passable, GameEvent* event) : passable(passable), event(event) {}

void Cell::setPassable(bool passable) {
    this->passable = passable;
}

bool Cell::isPassable() const {
    return passable;
}

GameEvent* Cell::getEvent() {
    return event;
}

void Cell::setEvent(GameEvent* event) {
    this->event = event;
}

Cell& Cell::operator=(Cell other) {
    if (this == &other) return *this;
    this->passable = other.passable;
    return *this;
}

