all:
	g++ --std=c++17 main.cpp Player.cpp PlayerController.cpp Cell.cpp GameField.cpp GameFieldCreator.cpp PlayerEvent.cpp FieldEvent.cpp EnemyEvent.cpp PointsEvent.cpp PositionEvent.cpp -o game