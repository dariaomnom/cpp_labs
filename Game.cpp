#include "Game.hpp"
#define FIELD_W_1 10
#define FIELD_H_1 10
#define FIELD_W_2 30
#define FIELD_H_2 30


Game::Game() {
//    player = Player();
//    field = GameField();
//    controller = PlayerController(player, field);
//    creator = GameFieldCreator(field, player, controller);
}

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

        if (command == Command::QUIT) {
            break;
        }
    }
}

void Game::setDifficulty(int lvl) {
    level = lvl;
}

bool Game::playLevel1() {
//    Player player;
//    GameField field(50, 50);
//    PlayerController controller(player,field);
//    GameFieldCreator creator(field, player, controller);
//    creator.createField(1);
    playGame(1);
//    controller.startGame();
    return true;
}
bool Game::playLevel2() {
//    Player player;
//    GameField field(50, 50);
//    PlayerController controller(player,field);
//    GameFieldCreator creator(field, player, controller);
//    creator.createField(1);
    playGame(1);
//    controller.startGame();
    return true;
}
//
//bool Game::playLevel2() {
//    return true;
//}

//Game::Game() : player(), gameField(), playerController(player, gameField) {
//    // Здесь вы можете инициализировать игру, например, установить начальный уровень сложности
//}

void Game::quit() {
    // Здесь вы можете завершить игру, например, сохранить прогресс и выйти из программы
//    clear();
//    std::string quit_message = "You are out of the game!";
//    printw("%s", quit_message.c_str());
//    mvprintw(10, 10, "%s", quit_message.c_str());
//    printw("\n");
//    refresh();
    clear();
    endwin();
//    cout << "You are out of the game!\n";
    cout << termcolor::red << "You are out of the game!\n" << termcolor::reset;
    exit(0);
}

//void Game::movePlayer(Direction direction) {
//    // Здесь вы можете переместить игрока в указанном направлении
//    controller.move(direction);
//}

bool Game::checkWin(GameField& field, PlayerController& controller) {
    if (field.getExit().first == controller.getX() && field.getExit().second == controller.getY()) {
        return true;
    }
    // Здесь вы можете проверить условия победы, например, достиг ли игрок конца игрового поля
    // Возвращаем true, если игрок выиграл, и false в противном случае
    return false;
}

bool Game::checkLoss(Player& player) {
    // Здесь вы можете проверить условия проигрыша, например, остались ли у игрока жизни
    // Возвращаем true, если игрок проиграл, и false в противном случае
    if (player.getLives() == 0)
        return true;
    return false;
}

void Game::restart() {
    // Здесь вы можете перезапустить игру, например, сбросить игровое поле и очки игрока
}


