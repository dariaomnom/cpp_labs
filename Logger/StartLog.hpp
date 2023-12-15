#include "LogLine.hpp"
#include "../PlayerController.hpp"
#include "../GameField.hpp"

#ifndef LABS_STARTLOG_HPP
#define LABS_STARTLOG_HPP

class StartLog: public LogLine {
public:
    StartLog(GameField& field);
    void print(std::ostream& out) const override;
private:
    GameField& field;
    int startX, startY, width, height;
};

#endif //LABS_STARTLOG_HPP
