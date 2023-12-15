#include "CommandLog.hpp"

CommandLog::CommandLog(char key, std::string command) : key (key), command(command) {}

void CommandLog::print(std::ostream& out) const {
    out << "The \"" << key << "\" key was pressed. The command \"" << command << "\" worked" << std::endl;
}