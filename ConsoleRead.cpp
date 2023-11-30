#include "ConsoleRead.hpp"

void ConsoleRead::readCommands() {
    this->showField();
    char dir;
    while (dir != 'q') {
        cin >> dir;
        switch (dir) {
            case 'w':
                this->move(Direction::UP);
                this->showField();
                break;
            case 's':
                this->move(Direction::DOWN);
                this->showField();
                break;
            case 'a':
                this->move(Direction::LEFT);
                this->showField();
                break;
            case 'd':
                this->move(Direction::RIGHT);
                this->showField();
                break;
            case 'p':
                player.printStats();
                break;
        }
    }
}