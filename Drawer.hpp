#include "PlayerController.hpp"
#include "GameField.hpp"

#include "Events/PlayerEvent.hpp"
#include "Events/PointsEvent.hpp"
#include "Events/LivesEvent.hpp"
#include "Events/EnemyEvent.hpp"
#include "Events/PositionEvent.hpp"
#define REGION_AROUND 9


#ifndef LABS_DRAWER_HPP
#define LABS_DRAWER_HPP

class Drawer {
private:
    PlayerController& controller;
    GameField& gameField;
    Player& player;
public:
    explicit Drawer(PlayerController& controller, GameField& gameField, Player& player);
    void drawField();
    void showStats();
};

#endif //LABS_DRAWER_HPP
