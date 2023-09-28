//#include <iostream>
//
//int main() {
//    std::cout << "Hello, World!" << std::endl;
//    return 0;
//}

#include <iostream>
#include "Player.hpp"
#include "PlayerController.hpp"
using namespace std;

//enum class Direction { UP, DOWN, LEFT, RIGHT };

//class Player {
//private:
//    int lives;
//    int points;
//
//public:
//    Player(int lives, int points) : lives(lives), points(points) {}
//
//    void addPoints(int points) {
//        this->points += points;
//        if (points < 0) points = 0;
//    }
//
//    void loseLife() {
//        lives--;
//        if (lives < 0) lives = 0;
//    }
//
//    void addLife(int lives) {
//        if (lives > 0) this->lives += lives; // no negative lives
//        if (this->lives > 10) this->lives = 10; // max 10 lives
//    }
//
//    int getLives() const { return lives; }
//    int getPoints() const { return points; }
//};

//class PlayerController {
//private:
//    Player& player;
//    int x, y;
//
//public:
//    PlayerController(Player& player, int startX, int startY) : player(player), x(startX), y(startY) {}
//
//    void move(Direction direction) {
//        switch (direction) {
//            case Direction::UP: y-1 >= 0 ? y-- : y = 0; break;
//            case Direction::DOWN: y++; break;
//            case Direction::LEFT: x-1 >= 0 ? x-- : x = 0; break;
//            case Direction::RIGHT: x++; break;
//        }
//    }
//
//    void printPosition() const {
//        std::cout << "Player is at (" << x << ", " << y << ")\n";
//    }
//};

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
