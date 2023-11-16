#ifndef LABS_GAME_HPP
#define LABS_GAME_HPP
#include "PlayerController.hpp"
#include "GameField.hpp"
#include "GameFieldCreator.hpp"
#include "InputHandler.hpp"
#include <iostream>
using namespace std;
#include <ncurses.h>
//#include <conio.h>
//#define FIELD_W 70
//#define FIELD_H 70

//class Game {
//private:
//    int level;
////    Player& player;
////    PlayerController& controller;
////    GameField& field;
////    GameFieldCreator& creator;
//public:
//    explicit Game();
//    void startGame();
//    bool playLevel1();
//    bool playLevel2();
//    void move();
//};


class Game {
private:
    int level;
//    Player& player;
//    GameField& field;
//    PlayerController& controller;
//    GameFieldCreator& creator;

public:
    explicit Game();
//    Game();

    bool playLevel1();
//    bool playLevel2();

    void startGame();
    void playGame(PlayerController& controller);
//    void quit();
    void setDifficulty(int level);
//    void movePlayer(Direction direction);
    bool checkWin(GameField& field, PlayerController& controller);
    bool checkLoss(Player& player);
    void restart();
    void handleCommand(PlayerController& controller, Command command);
};

#endif
