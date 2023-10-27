#include <iostream>
using namespace std;
#include "Cell.hpp"
#include "PlayerEvent.hpp"

#ifndef GAMEFIELD_HPP
#define GAMEFIELD_HPP

class GameField {
private:
    int width, height;
    Cell** cells;
//    GameEvent*** events;
    pair<int, int> entry, exit;
public:
    explicit GameField(int width = 10, int height = 10, pair<int,int> entry = make_pair(0,0), pair<int,int> exit = make_pair(99,99));
    GameField (GameField& other);
    GameField (GameField&& other);
    ~GameField();
    Cell& getCell(int x, int y);

//    GameEvent* getEvent(int x, int y);

//    void addEvent(int x, int y, GameEvent* event);

//    void randomCells(int density = 4);
    pair<int, int> getEntry() const;
    pair<int, int> getExit() const;
    pair<int, int> getSize() const;
    GameField& operator=(const GameField& other);
};
#endif