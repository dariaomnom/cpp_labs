#include "Warden.hpp"
#include "../PlayerController.hpp"

#ifndef CORDSWARDEN_HPP
#define CORDSWARDEN_HPP

class CordsWarden : public Warden {
private:
    PlayerController& controller;
    int oldX;
    int oldY;
public:
    CordsWarden(PlayerController& controller);
    bool updateInfo() override;
};

#endif
