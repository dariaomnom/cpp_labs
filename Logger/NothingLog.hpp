#include "LogLine.hpp"

#ifndef LABS_NOTHINGLOG_HPP
#define LABS_NOTHINGLOG_HPP

class NothingLog: public LogLine {
public:
    NothingLog(char key);
    void print(std::ostream& out) const override;
private:
    char key;
};

#endif //LABS_NOTHINGLOG_HPP
