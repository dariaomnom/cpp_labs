#include "LivesEvent.hpp"

LivesEvent::LivesEvent(Player &player) : PlayerEvent(player){}

void LivesEvent::triggerEvent() {
    player.addLives(ADDED_LIVES);
}