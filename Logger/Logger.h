#include <ostream>
#include <vector>
#include "LogLine.hpp"

#ifndef LABS_LOGGER_H
#define LABS_LOGGER_H

class Logger {
public:
    Logger(std::ostream& os);
    void addLog(const LogLine& msg);
    void writeLogs();
private:
    std::vector<const LogLine*> m_messages;
    std::ostream& m_os;
};

#endif //LABS_LOGGER_H
