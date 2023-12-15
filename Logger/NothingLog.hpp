#include "LogLine.hpp"

#ifndef LABS_NOTHINGLOG_HPP
#define LABS_NOTHINGLOG_HPP

class NothingLog: public LogLine {
private:
    char key;
public:
    NothingLog(char key);
    void print(std::ostream& out) const override;
};

#endif //LABS_NOTHINGLOG_HPP
