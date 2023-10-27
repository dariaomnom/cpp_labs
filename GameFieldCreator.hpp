#include "Player.hpp"
#include "PlayerController.hpp"
#include "GameField.hpp"
#include "EnemyEvent.hpp"
#include "PointsEvent.hpp"
#include "PositionEvent.hpp"

#ifndef GAMEFIELDCREATOR_HPP
#define GAMEFIELDCREATOR_HPP

class GameFieldCreator {
private:
    GameField& field;
    Player& player;
    PlayerController& controller;
public:
//    GameField createField(int level);
    explicit GameFieldCreator(GameField& field, Player& player, PlayerController& cl);
    ~GameFieldCreator() = default;
    void createField(int level);
};

#endif