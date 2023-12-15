#include "LogLine.hpp"

#ifndef LABS_COMMANDLOG_HPP
#define LABS_COMMANDLOG_HPP

class CommandLog: public LogLine {
public:
    CommandLog(char key, std::string command);
    void print(std::ostream& out) const override;
private:
    char key;
    std::string command;
};

#endif //LABS_COMMANDLOG_HPP
