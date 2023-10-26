
#ifndef LABS_ENEMY_HPP
#define LABS_ENEMY_HPP

#include "GameEvent.hpp"

class EnemyEvent : public GameEvent {
public:
    void triggerEvent(Player& player) override;
};

#endif
