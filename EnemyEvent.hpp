#ifndef LABS_ENEMYEVENT_HPP
#define LABS_ENEMYEVENT_HPP

#include "PlayerEvent.hpp"

class EnemyEvent : public PlayerEvent {
public:
    explicit EnemyEvent(Player& player);
    ~EnemyEvent() override = default;
    void triggerEvent() override;
};

#endif
