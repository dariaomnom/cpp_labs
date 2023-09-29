#include "Player.hpp"
#include "PlayerController.hpp"
#include <iostream>
using namespace std;

int main() {
    Player player(10, 0);
    player.printStats();

    PlayerController controller(player);
    controller.move(Direction::DOWN);
    controller.move(Direction::DOWN);
    controller.move(Direction::RIGHT);
    controller.printPosition();

    player.addPoints(230);

    player.loseLives();
    player.loseLives(3);

    player.printStats();

    return 0;
}
