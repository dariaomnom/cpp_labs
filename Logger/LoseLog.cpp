#include "LoseLog.hpp"

LoseLog::LoseLog(PlayerController& controller) : controller(controller) {
    X = controller.getX();
    Y = controller.getY();
}

void LoseLog::print(std::ostream& out) const {
    out << "Player lost on (" << X << "," << Y << ")." << std::endl;
}