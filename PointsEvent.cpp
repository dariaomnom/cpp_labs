#include "PointsEvent.hpp"

PointsEvent::PointsEvent(Player& player) : PlayerEvent(player) {}

void PointsEvent::triggerEvent() {
    player.addPoints(ADDED_POINTS);
}