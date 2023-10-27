#include "EnemyEvent.hpp"

EnemyEvent::EnemyEvent(Player &player) : PlayerEvent(player){}

void EnemyEvent::triggerEvent() {
    player.loseLives();
}