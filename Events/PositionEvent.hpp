#ifndef LABS_POSITIONEVENT_HPP
#define LABS_POSITIONEVENT_HPP

#include "GameEvent.hpp"
#include "FieldEvent.hpp"
#include "../Player.hpp"
#include "../PlayerController.hpp"
#include "../GameField.hpp"
#include "../Cell.hpp"

class PositionEvent : public FieldEvent {
public:
    explicit PositionEvent(Player& player, PlayerController& controller, GameField& field);
    ~PositionEvent() override = default;
    void triggerEvent() override;
};

#endif
