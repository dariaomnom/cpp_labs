#include "WinLog.hpp"

WinLog::WinLog(Player& player) : player(player) {}

void WinLog::print(std::ostream& out) const {
    out << "Player won (lives " << player.getLives() << ", points " << player.getPoints() << ", level " << player.getLevel() << ")" << std::endl;
}