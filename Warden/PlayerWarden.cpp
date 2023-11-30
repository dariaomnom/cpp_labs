#include "PlayerWarden.hpp"

PlayerWarden::PlayerWarden(Player& player) : player(player) {
    oldLives = player.getLives();
    oldPoints = player.getPoints();
    oldLevel = player.getLevel();
}

bool PlayerWarden::updateInfo() {
    if (player.getLives() != oldLives || player.getPoints() != oldPoints || player.getLevel() != oldLevel) {
        oldLives = player.getLives();
        oldPoints = player.getPoints();
        oldLevel = player.getLevel();
        return true;
    }
    return false;
}
