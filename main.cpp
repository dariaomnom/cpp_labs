#include <iostream>
#include "Player.hpp"
#include "PlayerController.hpp"
using namespace std;

int main() {
    Player player(10, 0);
    PlayerController controller(player);

    controller.move(DOWN);
    controller.move(DOWN);
    controller.move(RIGHT);
    controller.printPosition();

    player.addPoints(230);

    player.loseLives();
    player.loseLives(3);

    player.printStats();

    return 0;
}
