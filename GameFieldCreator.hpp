#include "Player.hpp"
#include "PlayerController.hpp"
#include "GameField.hpp"
#include "EnemyEvent.hpp"
#include "PointsEvent.hpp"
#include "LivesEvent.hpp"
#include "PositionEvent.hpp"

#ifndef GAMEFIELDCREATOR_HPP
#define GAMEFIELDCREATOR_HPP

class GameFieldCreator {
private:
    GameField& field;
    Player& player;
    PlayerController& controller;
public:
    explicit GameFieldCreator(GameField& field, Player& player, PlayerController& cl);
    ~GameFieldCreator() = default;
    void createField(int level);

    bool isSafe(GameField& field, bool **visited, int x, int y, int width, int height);

    bool findPath(GameField& field, bool **visited, int x, int y, int exitX, int exitY, int width, int height);

    bool checkPath(GameField& field);

    bool checkRandomCords(GameField& field, int x, int y);
};

#endif