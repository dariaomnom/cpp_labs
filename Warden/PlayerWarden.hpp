#include "Warden.hpp"
#include "../Player.hpp"

#ifndef PLAYERWARDEN_HPP
#define PLAYERWARDEN_HPP

class PlayerWarden : public Warden {
private:
    Player& player;
    int oldLives;
    int oldPoints;
    int oldLevel;
public:
    explicit PlayerWarden(Player& player);
    bool updateInfo() override;
};

#endif
