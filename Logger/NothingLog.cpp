#include "NothingLog.hpp"

NothingLog::NothingLog(char key) : key (key) {}

void NothingLog::print(std::ostream& out) const {
    out << "The \"" << key << "\" key is pressed. No command worked." << std::endl;
}