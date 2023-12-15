#include "LogLine.hpp"
#include "../Player.hpp"

#ifndef LABS_PLAYERWONLOG_HPP
#define LABS_PLAYERWONLOG_HPP

class PlayerWonLog: public LogLine {
public:
    PlayerWonLog(Player& player);
    void print(std::ostream& out) const override;
private:
    Player& player;
};

#endif //LABS_PLAYERWONLOG_HPP
