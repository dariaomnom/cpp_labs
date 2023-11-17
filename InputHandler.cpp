
#include "InputHandler.hpp"

#include <fstream>
#include <sstream>

//class InputHandler {
//private:
//std::map<std::string, Command> InputHandler::commandMap;
//std::ifstream file;
Command InputHandler::stringToCommand(const std::string& command) {
//     Здесь вы можете реализовать преобразование строки в команду
//     Например, если command == "START", то возвращаем Command::START
//    switch (command) {
//        case "QUIT":
//            return Command::QUIT;
//        case "MOVE_UP":
//            return Command::MOVE_UP;
//        case "MOVE_LEFT":
//            return Command::MOVE_LEFT;
//        case "MOVE_DOWN":
//            return Command::MOVE_DOWN;
//        case "MOVE_RIGHT":
//            return Command::MOVE_RIGHT;
//        case "RESTART":
//            return Command::RESTART;
//        case "PLAY_LVL_1":
//            return Command::PLAY_LVL_1;
//    }
    if (command == "QUIT")
            return Command::QUIT;
    if (command == "MOVE_UP")
            return Command::MOVE_UP;
    if (command == "MOVE_LEFT")
            return Command::MOVE_LEFT;
    if (command == "MOVE_DOWN")
            return Command::MOVE_DOWN;
    if (command == "MOVE_RIGHT")
            return Command::MOVE_RIGHT;
    if (command == "RESTART")
            return Command::RESTART;
    if (command == "PLAY_LVL_1")
            return Command::PLAY_LVL_1;
    if (command == "PLAY_LVL_2")
        return Command::PLAY_LVL_2;
    if (command == "STATS")
        return Command::STATS;
    if (command == "NOTHING")
            return Command::NOTHING;
    return Command::NOTHING;
}

//public:
InputHandler::InputHandler(const std::string& filename) : file(filename) {
    if (!file) {
        throw std::runtime_error("Could not open file");
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string key;
        std::string command;
        if (!(iss >> key >> command)) {
            throw std::runtime_error("Invalid file format");
        }
        commandMap[key] = stringToCommand(command);
    }
}

InputHandler::~InputHandler() {
    if (file) {
        file.close();
    }
}

Command InputHandler::handleInput(const std::string& input) {
    auto it = commandMap.find(input);
    if (it == commandMap.end()) {
//        throw std::runtime_error("Invalid command");
        return Command::NOTHING;
    }
    return it->second;
}

//}
