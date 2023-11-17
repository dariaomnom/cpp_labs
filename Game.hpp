#ifndef LABS_GAME_HPP
#define LABS_GAME_HPP
#include "PlayerController.hpp"
#include "GameField.hpp"
#include "GameFieldCreator.hpp"
#include "InputHandler.hpp"
#include "lib/termcolor.hpp"
#include <iostream>
using namespace std;
#include <ncurses.h>
#include <array>

class Game {
private:
    int level;

public:
    explicit Game();
//    bool playLevel1();
//    bool playLevel2();
    void startGame();
    void playGame(int lvl);
    void quit();
    void setDifficulty(int level);
    bool checkWin(GameField& field, PlayerController& controller);
    bool checkLoss(Player& player);
    void restart();
    void handleCommand(PlayerController& controller, Command command);
};

#endif
