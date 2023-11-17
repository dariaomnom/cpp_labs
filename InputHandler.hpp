#include <iostream>
using namespace std;
#include <fstream>
#include <map>
#include <set>
#include <string>
#include <ncurses.h>
#ifndef LABS_INPUTHANDLER_HPP
#define LABS_INPUTHANDLER_HPP

enum class Command { QUIT, MOVE_UP, MOVE_DOWN, MOVE_LEFT, MOVE_RIGHT, RESTART, STATS, PLAY_LVL_1, PLAY_LVL_2, NOTHING };

class InputHandler {
private:
    std::map<std::string, Command> commandMap;
    std::set<std::string> commandSet;
    std::ifstream file;
    Command stringToCommand(const std::string& command);

public:
    explicit InputHandler(const std::string& filename);
    ~InputHandler();
    Command handleInput(const std::string& input);
};


#endif
