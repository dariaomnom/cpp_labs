#include "LogLine.hpp"

#ifndef LABS_COMMANDLOG_HPP
#define LABS_COMMANDLOG_HPP

class CommandLog: public LogLine {
private:
    char key;
    std::string command;
public:
    CommandLog(char key, std::string command);
    void print(std::ostream& out) const override;
};

#endif //LABS_COMMANDLOG_HPP
