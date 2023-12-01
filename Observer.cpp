#include "Observer.hpp"

//Observer::Observer(MonitorPlayerStats& monPlStats, MonitorCoordinates& monCoords, FieldShow& viewer) :
//        monPlStats(monPlStats), monCoords(monCoords), viewer(viewer) {}

Observer::Observer(GameStateWarden& gameStateWarden, PlayerWarden& playerWarden,
        CordsWarden& cordsWarden, EventsWarden& eventsWarden, Drawer& drawer) :
            gameStateWarden(gameStateWarden),
            playerWarden(playerWarden),
            cordsWarden(cordsWarden),
            eventsWarden(eventsWarden),
            drawer(drawer) {}


void Observer::overWatch() {
    gameStateWarden.updateInfo();
    playerWarden.updateInfo();
    bool cords = cordsWarden.updateInfo();
    bool events = eventsWarden.updateInfo();


    if (cords || events){
        drawer.drawField();
    } else {
        drawer.drawField();
    }
}

void Observer::overWatchGameState() {
    gameStateWarden.updateInfo();
}

void Observer::overWatchPlayer() {
    playerWarden.updateInfo();
}
void Observer::overWatchCords() {
    cordsWarden.updateInfo();
}
void Observer::overWatchEvents() {
    eventsWarden.updateInfo();
}