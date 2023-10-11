#include "Player.hpp"
#include "PlayerController.hpp"
#include "Cell.hpp"
#include "GameField.hpp"

#include <iostream>
using namespace std;

int main() {

    Player caron;
    GameField home;
    PlayerController carons_steps(caron, home);

    return 0;
}
