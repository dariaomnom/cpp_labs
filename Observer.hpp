#include "Drawer.hpp"
#include "Warden/GameStateWarden.hpp"
#include "Warden/PlayerWarden.hpp"
#include "Warden/CordsWarden.hpp"
#include "Warden/EventsWarden.hpp"
#include "Game.hpp"

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
    void overWatchGameState();
    void overWatchPlayer();
    void overWatchCords();
    void overWatchEvents();
};

#endif
