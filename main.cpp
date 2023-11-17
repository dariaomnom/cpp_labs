#include "Player.hpp"
#include "PlayerController.hpp"
#include "Cell.hpp"
#include "GameField.hpp"
#include "PlayerEvent.hpp"
#include "GameFieldCreator.hpp"
#include "Game.hpp"
#include <ncurses.h>

#include <iostream>
using namespace std;
#define FIELD_LVL 2
#define FIELD_SIZE 10
#define FIELD_W 70
#define FIELD_H 70


int main() {
    initscr();
    start_color();

    Game game;
    game.startGame();

    endwin();
    return 0;
}
