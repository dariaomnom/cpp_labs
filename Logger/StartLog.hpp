#include "LogLine.hpp"
#include "../PlayerController.hpp"
#include "../GameField.hpp"

#ifndef LABS_STARTLOG_HPP
#define LABS_STARTLOG_HPP

class StartLog: public LogLine {
public:
    StartLog(PlayerController& controller, GameField& field);
    void print(std::ostream& out) const override;
private:
    PlayerController& controller;
    GameField& field;
};

#endif //LABS_STARTLOG_HPP
