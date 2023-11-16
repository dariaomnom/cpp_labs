#include "Game.hpp"

Game::Game() {
//    player = Player();
//    field = GameField();
//    controller = PlayerController(player, field);
//    creator = GameFieldCreator(field, player, controller);
}

void Game::handleCommand(PlayerController& controller, Command command) {
    switch(command) {
        case Command::START:
            startGame();
            break;
        case Command::QUIT:
//            quit();
            break;
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
        case Command::SET_DIFFICULTY:
//            this->level =
            break;
        case Command::CHECK_WIN:
            break;
        case Command::CHECK_LOSS:
            break;
        case Command::RESTART:
            break;
            // и так далее для остальных команд
    }
}

void Game::startGame() {

    char lvl = '1';
//    cin >> lvl;
    level = lvl;
    if (lvl == '1') {
        playLevel1();
    }
//    else if (lvl == '2') {
//        playLevel2();
//    }

}

void Game::playGame(PlayerController& controller) {
    InputHandler inputHandler("commandMap.txt");

    addstr("Game has started");

    // Запускаем цикл игры
    while (true) {
        // Считываем символ, введенный пользователем
        int ch = getch();

        // Преобразуем символ в строку
        std::string input(1, ch);

        // Получаем команду, соответствующую введенному символу
        Command command = inputHandler.handleInput(input);

        // Обрабатываем команду
        handleCommand(controller, command);

        // Если была введена команда QUIT, выходим из цикла
        if (command == Command::QUIT) {
            break;
        }
    }
}

void Game::setDifficulty(int lvl) {
    level = lvl;
}

bool Game::playLevel1() {
    Player player;
    GameField field(10, 10);
    PlayerController controller(player,field);
    GameFieldCreator creator(field, player, controller);
    creator.createField(1);
    playGame(controller);
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

//void Game::start() {
//    // Здесь вы можете начать игру, например, отобразить игровое поле и начать цикл игры
//}

//void Game::quit() {
//    // Здесь вы можете завершить игру, например, сохранить прогресс и выйти из программы
//}

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


//
//void Game::move() {
//    char dir;
//    while (dir != 'q') {
//        cin >> dir;
//        switch (dir) {
//            case 'w':
//                this->move(Direction::UP);
//                this->showField();
//                break;
//            case 's':
//                this->move(Direction::DOWN);
//                this->showField();
//                break;
//            case 'a':
//                this->move(Direction::LEFT);
//                this->showField();
//                break;
//            case 'd':
//                this->move(Direction::RIGHT);
//                this->showField();
//                break;
//            case 'p':
//                player.printStats();
//                break;
//        }
//    }
//}

