#ifndef LABS_POINTSEVENT_HPP
#define LABS_POINTSEVENT_HPP

#include "PlayerEvent.hpp"
#define ADDED_POINTS 10

class PointsEvent : public PlayerEvent {
public:
    explicit PointsEvent(Player& player);
    ~PointsEvent() override = default;
    void triggerEvent() override;
};

#endif
