#include "Game.hpp"
#define FIELD_W_1 10
#define FIELD_H_1 10
#define FIELD_W_2 30
#define FIELD_H_2 30


Game::Game() {}

void Game::handleCommand(PlayerController& controller, Command command) {
    switch(command) {
        case Command::MOVE_UP:
            controller.move(Direction::UP);
            break;
        case Command::MOVE_LEFT:
            controller.move(Direction::LEFT);
            break;
        case Command::MOVE_DOWN:
            controller.move(Direction::DOWN);
            break;
        case Command::MOVE_RIGHT:
            controller.move(Direction::RIGHT);
            break;
        case Command::RESTART:
            startGame();
            break;
        case Command::PLAY_LVL_1:
            break;
        case Command::PLAY_LVL_2:
            break;
        case Command::QUIT:
            quit();
            break;
        case Command::NOTHING:
            break;
    }
}

void Game::startGame() {
    InputHandler inputHandler("commandMap.txt");

    while (true) {
        clear();
        init_pair(5, COLOR_CYAN, COLOR_BLACK);
        attron(COLOR_PAIR(5));
        std::string n_message = "\n";
        printw("%s", n_message.c_str());
        std::string level_message = "   Welcome to the game!\n   Select difficulty level (1 or 2)";
        printw("%s", level_message.c_str());
        attroff(COLOR_PAIR(5));
        refresh();
        int ch = getch();
        std::string input(1, ch);
        Command command = inputHandler.handleInput(input);
        if (command == Command::PLAY_LVL_1) {
            this->level = 1;
            playGame(1);
            break;
        }
        if (command == Command::PLAY_LVL_2) {
            this->level = 2;
            playGame(2);
            break;
        }
    }

}

void Game::playGame(int lvl) {
    Player player;
    std::array<int, 2> size_level;
    lvl == 1 ? size_level = {10, 10} : size_level = {30, 30};

    GameField field(size_level[0], size_level[1]);
    PlayerController controller(player,field);
    GameFieldCreator creator(field, player, controller);
    if (lvl == 1)
        creator.createField(1);
    else if (lvl == 2)
        creator.createField(2);


    InputHandler inputHandler("commandMap.txt");

    clear();
    init_pair(4, COLOR_CYAN, COLOR_BLACK);
    attron(COLOR_PAIR(4));
    std::string n_message = "\n";
    printw("%s", n_message.c_str());
    std::string start_message = "   Press any key to start the game";
    printw("%s", start_message.c_str());
    attroff(COLOR_PAIR(4));
    refresh();
    int ch = getch();



    while (true) {
        controller.drawGameField();
        int ch = getch();
        std::string input(1, ch);
        Command command = inputHandler.handleInput(input);
        handleCommand(controller, command);

        if (checkWin(field, controller)) {
            clear();
            endwin();
            printw("%s", n_message.c_str());
            init_pair(6, COLOR_GREEN, COLOR_BLACK);
            attron(COLOR_PAIR(6));
            std::string win_message = "   You win!\n   Press any key to restart the game\n   or 'q' to quit";
            printw("%s", win_message.c_str());
            attroff(COLOR_PAIR(6));
            ch = getch();
            if (ch == 113) // q
                exit(0);
            else
                startGame();
        }

        if (checkLoss(player)) {
            clear();
            endwin();
            printw("%s", n_message.c_str());
            init_pair(7, COLOR_RED, COLOR_BLACK);
            attron(COLOR_PAIR(7));
            std::string lose_message = "   Game over!\n   Press any key to start the game\n   or 'q' to quit";
            printw("%s", lose_message.c_str());
            attroff(COLOR_PAIR(7));
            ch = getch();
            if (ch == 113) // q
                exit(0);
            else
                startGame();
        }

        if (command == Command::QUIT) {
            break;
        }
    }
}

void Game::setDifficulty(int lvl) {
    level = lvl;
}

//bool Game::playLevel1() {
//    playGame(1);
//    return true;
//}
//bool Game::playLevel2() {
//    playGame(2);
//    return true;
//}

void Game::quit() {
//    clear();
//    endwin();
//    cout << termcolor::red << "You are out of the game!\n" << termcolor::reset;
//    exit(0);

    clear();
    endwin();
    std::string n_message = "\n";
    printw("%s", n_message.c_str());
    init_pair(6, COLOR_YELLOW, COLOR_BLACK);
    attron(COLOR_PAIR(6));
    std::string win_message = "   Do you want to quit?\n   Press any key to restart the game\n   or 'q' to quit";
    printw("%s", win_message.c_str());
    attroff(COLOR_PAIR(6));
    int ch = getch();
    if (ch == 113) // q
        exit(0);
    else
        startGame();
}

bool Game::checkWin(GameField& field, PlayerController& controller) {
    if (field.getExit().first == controller.getX() && field.getExit().second == controller.getY())
        return true;
    return false;
}

bool Game::checkLoss(Player& player) {
    if (player.getLives() == 0)
        return true;
    return false;
}
