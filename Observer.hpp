#include "Drawer.hpp"
#include "GameStateWarden.hpp"
#include "PlayerWarden.hpp"
#include "CordsWarden.hpp"
#include "EventsWarden.hpp"

#ifndef OBSERVER_HPP
#define OBSERVER_HPP

class Observer {
private:
    GameStateWarden& gameStateWarden;
    PlayerWarden& playerWarden;
    CordsWarden& cordsWarden;
    EventsWarden& eventsWarden;
    Drawer& drawer;
public:
    explicit Observer(GameStateWarden& gameStateWarden, PlayerWarden& playerWarden, CordsWarden& cordsWarden, EventsWarden& eventsWarden, Drawer& drawer);
    void overWatch();
};

#endif
