
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
    return Command::START;
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
        throw std::runtime_error("Invalid command");
    }
    return it->second;
}

//}
