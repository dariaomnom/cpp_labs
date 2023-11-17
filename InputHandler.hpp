#include <iostream>
using namespace std;
//#include "map"
#include <fstream>
#include <map>
#include <string>
//#include "ifstream"
#ifndef LABS_INPUTHANDLER_HPP
#define LABS_INPUTHANDLER_HPP

//enum class Command { START, QUIT, SET_DIFFICULTY, MOVE_UP, MOVE_DOWN, MOVE_LEFT, MOVE_RIGHT, CHECK_WIN, CHECK_LOSS, RESTART, PLAY_LVL_1 };
enum class Command { QUIT, MOVE_UP, MOVE_DOWN, MOVE_LEFT, MOVE_RIGHT, RESTART, PLAY_LVL_1, PLAY_LVL_2, NOTHING };

class InputHandler {
private:
    std::map<std::string, Command> commandMap;
    std::ifstream file;
    Command stringToCommand(const std::string& command);

public:
    explicit InputHandler(const std::string& filename);
    ~InputHandler();
    Command handleInput(const std::string& input);
};


#endif
