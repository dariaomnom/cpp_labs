#ifndef LABS_LIVESEVENT_HPP
#define LABS_LIVESEVENT_HPP

#include "PlayerEvent.hpp"

class LivesEvent : public PlayerEvent {
public:
    explicit LivesEvent(Player& player);
    ~LivesEvent() override = default;
    void triggerEvent() override;
};

#endif
