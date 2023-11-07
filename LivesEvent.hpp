#ifndef LABS_LIVESEVENT_HPP
#define LABS_LIVESEVENT_HPP

#include "PlayerEvent.hpp"
#define ADDED_LIVES 3

class LivesEvent : public PlayerEvent {
public:
    explicit LivesEvent(Player& player);
    ~LivesEvent() override = default;
    void triggerEvent() override;
};

#endif
