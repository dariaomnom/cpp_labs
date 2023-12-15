#include "LogLine.hpp"
#include "../PlayerController.hpp"

#ifndef LABS_LOSELOG_HPP
#define LABS_LOSELOG_HPP

class LoseLog: public LogLine {
private:
    PlayerController& controller;
    int X, Y;
public:
    LoseLog(PlayerController& controller);
    void print(std::ostream& out) const override;
};

#endif //LABS_LOSELOG_HPP
