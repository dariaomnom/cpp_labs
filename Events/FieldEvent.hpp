#ifndef LABS_FIELDEVENT_HPP
#define LABS_FIELDEVENT_HPP

#include "GameEvent.hpp"
#include "../Player.hpp"
#include "../PlayerController.hpp"
#include "../GameField.hpp"

class FieldEvent : public GameEvent{
protected:
    Player& player;
    PlayerController& controller;
    GameField& field;
public:
    explicit FieldEvent(Player& player, PlayerController& controller, GameField& field);
    virtual ~FieldEvent() override = default;
    void triggerEvent() override = 0;
};

#endif
