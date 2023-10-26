#ifndef LABS_POSITIONEVENT_HPP
#define LABS_POSITIONEVENT_HPP

#include "FieldEvent.hpp"

class PositionEvent : public FieldEvent {
public:
    explicit PositionEvent(Player& player, PlayerController& controller, GameField& field);
    ~PositionEvent() override = default;
    void triggerEvent() override;
};

#endif
