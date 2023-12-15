#include "StartLog.hpp"

StartLog::StartLog(GameField& field) : field(field) {
    width = field.getSize().first;
    height = field.getSize().second;
    startX = field.getEntry().first;
    startY = field.getEntry().second;
}

void StartLog::print(std::ostream& out) const {
    out << "Game started. Size of field: " << width << "x" << height << ". Start: (" << startX << "," << startY << ")." << std::endl;
}