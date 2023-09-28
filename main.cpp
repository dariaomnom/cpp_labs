#include <iostream>
#include "Player.hpp"
#include "PlayerController.hpp"
using namespace std;

int main() {
    Player player(10, 0);
    PlayerController controller(player, 0, 0);

    controller.move(DOWN);
    controller.move(DOWN);
    controller.move(RIGHT);
    controller.printPosition();

    player.addPoints(50);
    std::cout << "Player has " << player.getPoints() << " points\n";
    player.addPoints(50);
    std::cout << "Player has " << player.getLevel() << " level\n";
    std::cout << "Player has " << player.getPoints() << " points\n";
    player.addPoints(60);
    std::cout << "Player has " << player.getPoints() << " points\n";
    std::cout << "Player has " << player.getLevel() << " level\n";
    player.addPoints(50);
    std::cout << "Player has " << player.getLevel() << " level\n";
    std::cout << "Player has " << player.getPoints() << " points\n";


    player.loseLife();
    player.loseLife();
    player.addLife(3);
//    std::cout << "Player has " << player.getLives() << " lives\n";



    return 0;
}
