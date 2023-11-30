#include "Observer.hpp"

Observer::Observer(MonitorPlayerStats& monPlStats, MonitorCoordinates& monCoords, FieldShow& viewer) :
        monPlStats(monPlStats), monCoords(monCoords), viewer(viewer) {}

Observer::Observer(GameStateWarden& gameStateWarden, PlayerWarden& playerWarden,
        CordsWarden& cordsWarden, EventsWarden& eventsWarden, Drawer& drawer) :
            gameStateWarden(gameStateWarden),
            playerWarden(playerWarden),
            cordsWarden(cordsWarden),
            eventsWarden(eventsWarden),
            drawer(drawer) {}


void ObserverGame::overWatch() {
    bool gameStateWarden =
    bool monPlStatsBool = monPlStats.update();
    bool monCoordinatesBool = monCoords.update();
    if (monPlStatsBool || monCoordinatesBool){
        viewer.showField();
    }
}
