#include "EnemyEvent.hpp"

EnemyEvent::EnemyEvent(Player &player) : PlayerEvent(player){}

void EnemyEvent::triggerEvent() {
    if (player.getLevel() >= WIN_LVL)
        player.addPoints(WON_POINTS);
    else
        player.loseLives(LOST_LIVES);
}