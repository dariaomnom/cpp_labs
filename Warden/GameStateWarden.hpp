#include "Warden.hpp"
#include "../PlayerController.hpp"
#include "../GameField.hpp"
#include "../Player.hpp"
#include "../Game.hpp"

#ifndef GAMESTATEWARDEN_HPP
#define GAMESTATEWARDEN_HPP

enum class GameState { WIN, LOSS, IN_PROGRESS };

class GameStateWarden : public Warden {
private:
//    Game& game;
    PlayerController& controller;
    GameField& field;
    Player& player;
    GameState oldState;
public:
    explicit GameStateWarden(PlayerController& controller, GameField& field, Player& player);
    bool updateInfo() override;
};

#endif
