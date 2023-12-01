#include "Warden.hpp"
#include "../PlayerController.hpp"
#include "../GameField.hpp"
#include "../Events/GameEvent.hpp"

#ifndef EVENTSWARDEN_HPP
#define EVENTSWARDEN_HPP

class EventsWarden : public Warden {
private:
    PlayerController& controller;
    GameField oldField;
    GameField& progressField;
public:
    explicit EventsWarden(PlayerController& controller, GameField& progressField);
    bool updateInfo() override;
};

#endif
