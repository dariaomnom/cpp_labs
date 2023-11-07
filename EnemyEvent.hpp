#ifndef LABS_ENEMYEVENT_HPP
#define LABS_ENEMYEVENT_HPP

#include "PlayerEvent.hpp"
#define LOST_LIVES 1
#define WON_POINTS 20
#define WIN_LVL 3

class EnemyEvent : public PlayerEvent {
public:
    explicit EnemyEvent(Player& player);
    ~EnemyEvent() override = default;
    void triggerEvent() override;
};

#endif
