#include "GameStateWarden.hpp"
#include "../Game.hpp"

GameStateWarden::GameStateWarden(PlayerController& controller, GameField& field, Player& player) :
controller(controller), field(field), player(player) {
    oldState = GameState::IN_PROGRESS;
}

bool GameStateWarden::updateInfo() {
    Game game;
    if (game.checkWin(field, controller) && oldState != GameState::WIN) {
        oldState = GameState::WIN;
        return true;
    } else if (game.checkLoss(player)  && oldState != GameState::LOSS) {
        oldState = GameState::LOSS;
        return true;
    }
    return false;
}
