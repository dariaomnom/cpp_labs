all:
	g++ --std=c++17 main.cpp Player.cpp PlayerController.cpp Cell.cpp GameField.cpp GameFieldCreator.cpp GameEvent.cpp -o game
