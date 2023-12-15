#include "PlayerWonLog.hpp"

PlayerWonLog::PlayerWonLog(Player& player) : player(player) {}

void/*std::ostream&*/ PlayerWonLog::print(std::ostream& out) const {
    out << "Player won" << std::endl;
}