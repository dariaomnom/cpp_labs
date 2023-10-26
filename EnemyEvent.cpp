#include "EnemyEvent.hpp"

void EnemyEvent::triggerEvent() {
    player.loseLives();
}