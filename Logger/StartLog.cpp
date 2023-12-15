#include "StartLog.hpp"

StartLog::StartLog(PlayerController& controller, GameField& field) : controller(controller), field(field) {}

void StartLog::print(std::ostream& out) const {
    out << "Start game" << std::endl;
}