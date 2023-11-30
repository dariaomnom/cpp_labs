#ifndef GAMEEVENT_HPP
#define GAMEEVENT_HPP

#include "GameEvent.hpp"
#include "../Player.hpp"

class PlayerEvent : public GameEvent {
protected:
    Player& player;
public:
    explicit PlayerEvent(Player& player);
    virtual ~PlayerEvent() override = default;
    void triggerEvent() override = 0;
};

#endif