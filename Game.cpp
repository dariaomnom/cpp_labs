#include "Game.hpp"
#define FIELD_W_1 10
#define FIELD_H_1 10
#define FIELD_W_2 30
#define FIELD_H_2 30


Game::Game() {}

void Game::handleCommand(Player& player, PlayerController& controller, Command command) {
    int stat_char;
    std::string stats_message = "\n   Press any key to continue\n";
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
//            controller.drawGameField();
            break;
        case Command::PLAY_LVL_2:
//            controller.drawGameField();
            break;
        case Command::STATS:
            player.printStats();
            printw("%s", stats_message.c_str());
            stat_char = getch();
            controller.drawGameField();
            refresh();
            endwin();
            break;
        case Command::QUIT:
            quit();
            break;
        case Command::NOTHING:
            controller.drawGameField();
            break;
    }
}

void Game::startGame() {
    InputHandler inputHandler("commandMap.txt");

    while (true) {
        clear();
        init_pair(5, COLOR_CYAN, COLOR_BLACK);
        attron(COLOR_PAIR(5));
        std::string level_message = "\n   Welcome to the game!\n   Select difficulty level (1 or 2)\n";
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
    lvl == 1 ? size_level = {FIELD_W_1, FIELD_H_1} : size_level = {FIELD_W_2, FIELD_H_2};

    GameField field(size_level[0], size_level[1]);
    PlayerController controller(player,field);
    GameFieldCreator creator(field, player, controller);
    if (lvl == 1)
        creator.createField(1);
    else if (lvl == 2)
        creator.createField(2);


    Drawer drawer = Drawer(controller, field, player);
    GameStateWarden gameStateWarden = GameStateWarden(controller, field, player);
    PlayerWarden playerWarden = PlayerWarden(player);
    CordsWarden cordsWarden = CordsWarden(controller);
    EventsWarden eventsWarden = EventsWarden(controller, field);
    Observer observer = Observer(gameStateWarden, playerWarden, cordsWarden, eventsWarden, drawer);


    InputHandler inputHandler("commandMap.txt");
    clear();
    init_pair(4, COLOR_CYAN, COLOR_BLACK);
    attron(COLOR_PAIR(4));
    std::string start_message = "\n   Press any key to start the game\n";
    printw("%s", start_message.c_str());
    attroff(COLOR_PAIR(4));
    refresh();
    int ch = getch();

    controller.drawGameField();


    while (true) {
        observer.overWatch();
//        if (ch != 112)
//            controller.drawGameField();
        ch = getch();
        std::string input(1, ch);
        Command command = inputHandler.handleInput(input);
        handleCommand(player, controller, command);

//        observer.overWatch();

        if (checkWin(field, controller)) {
            clear();
            endwin();
            player.printStats();
            init_pair(6, COLOR_GREEN, COLOR_BLACK);
            attron(COLOR_PAIR(6));
            std::string win_message = "\n   You win!\n   Press any key to restart the game\n   or 'q' to quit\n";
            printw("%s", win_message.c_str());
            attroff(COLOR_PAIR(6));
            ch = getch();
            endwin();
            if (ch == 113) // q
                exit(0);
            else
                startGame();
        }

        if (checkLoss(player)) {
            clear();
            endwin();
            player.printStats();
            init_pair(7, COLOR_RED, COLOR_BLACK);
            attron(COLOR_PAIR(7));
            std::string lose_message = "\n   Game over!\n   Press any key to start the game\n   or 'q' to quit\n";
            printw("%s", lose_message.c_str());
            attroff(COLOR_PAIR(7));
            ch = getch();
            endwin();
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

void Game::quit() {
    clear();
    endwin();
    init_pair(6, COLOR_YELLOW, COLOR_BLACK);
    attron(COLOR_PAIR(6));
    std::string win_message = "\n   Do you want to quit?\n   Press any key to restart the game\n   or 'q' to quit\n";
    printw("%s", win_message.c_str());
    attroff(COLOR_PAIR(6));
    int ch = getch();
    endwin();
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
