#include "LogLine.hpp"
#include "../Player.hpp"

#ifndef LABS_WINLOG_HPP
#define LABS_WINLOG_HPP

class WinLog: public LogLine {
private:
    Player& player;
    int lives, points, level;
public:
    WinLog(Player& player);
    void print(std::ostream& out) const override;
};

#endif //LABS_WINLOG_HPP
