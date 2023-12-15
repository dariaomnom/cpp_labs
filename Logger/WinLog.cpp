#include "WinLog.hpp"

WinLog::WinLog(Player& player) : player(player) {
    lives = player.getLives();
    points = player.getPoints();
    level = player.getLevel();
}

void WinLog::print(std::ostream& out) const {
    out << "Player won. Lives: " << lives << ", points: " << points << ", level: " << level << "." << std::endl;
}