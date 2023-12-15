#ifndef LABS_GAME_HPP
#define LABS_GAME_HPP
#include "PlayerController.hpp"
#include "GameField.hpp"
#include "GameFieldCreator.hpp"
#include "InputHandler.hpp"
#include "Observer.hpp"
#include "Logger/LogLine.hpp"
#include "Logger/Logger.h"
#include "Logger/StartLog.hpp"
#include "Logger/WinLog.hpp"
#include "Logger/LoseLog.hpp"
#include "Logger/CommandLog.hpp"
#include "Logger/NothingLog.hpp"

#include <fstream>

#include "lib/termcolor.hpp"
#include <iostream>
#include <ostream>
using namespace std;
#include <ncurses.h>
#include <array>

class Game {
private:
    int level;
    Logger* consoleLogger = nullptr;
    Logger* fileLogger = nullptr;
    std::ofstream file;
    int selectedLog = 3;

public:
    explicit Game();

    void selectLogAndStart();

    void startGame();
    void playGame(int lvl);
    void quit();
    void setDifficulty(int level);
    bool checkWin(GameField& field, PlayerController& controller);
    bool checkLoss(Player& player);
    void restart();
    void handleCommand(Player& player, PlayerController& controller, Command command, char char_symbol, Drawer& drawer);
};

#endif
