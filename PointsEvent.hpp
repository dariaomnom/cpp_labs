#ifndef LABS_POINTSEVENT_HPP
#define LABS_POINTSEVENT_HPP

#include "PlayerEvent.hpp"

class PointsEvent : public PlayerEvent {
public:
    explicit PointsEvent(Player& player);
    ~PointsEvent() override = default;
    void triggerEvent() override;
};

#endif
