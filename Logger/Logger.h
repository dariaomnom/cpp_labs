#include <ostream>
#include <vector>
#include "LogLine.hpp"

#ifndef LABS_LOGGER_H
#define LABS_LOGGER_H

class Logger {
private:
    std::vector<const LogLine*> lines;
    std::ostream& out_line;
public:
    Logger(std::ostream& os);
    void addLog(const LogLine& msg);
    void writeLogs();
};

#endif //LABS_LOGGER_H
