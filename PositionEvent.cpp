#include "PositionEvent.hpp"

PositionEvent::PositionEvent(Player &player, PlayerController &controller, GameField &field) : FieldEvent(player, controller, field){}

void PositionEvent::triggerEvent() {
    // one-off teleport
    field.getCell(controller.getX(), controller.getY()).setEvent(nullptr);

    int x = controller.getX();
    int y = controller.getY();
    int newX = x + 5 < field.getSize().first ? x + 5 : field.getSize().first-1;
    int newY = y + 5 < field.getSize().second ? y + 5 : field.getSize().second-1;

    if (field.getCell(newX, newY).isPassable()) {
//        controller.getX() + 5 < field.getSize().first ? controller.setX(controller.getX() + 5) : controller.setX(field.getSize().first-1);
//        controller.getY() + 5 < field.getSize().second ? controller.setY(controller.getY() + 5) : controller.setY(field.getSize().second-1);
        controller.setX(newX);
        controller.setY(newY);
    } else if (field.getCell(newX, y).isPassable()) {
        controller.setX(newX);
    } else if (field.getCell(x, newY).isPassable()) {
        controller.setY(newY);
    }

//    if (field.getCell(controller.getX() + 5 < field.getSize().first ? controller.getX() + 5 : field.getSize().first-1,
//                      controller.getY() + 5 < field.getSize().second ? controller.getY() + 5 : field.getSize().second-1).isPassable()) {
//        controller.getX() + 5 < field.getSize().first ? controller.setX(controller.getX() + 5) : controller.setX(field.getSize().first-1);
//        controller.getY() + 5 < field.getSize().second ? controller.setY(controller.getY() + 5) : controller.setY(field.getSize().second-1);
////        controller.setX(controller.getX() + 5);
////        controller.setY(controller.getY() + 5);
//    } else if (field.getCell(controller.getX() + 5, controller.getY()).isPassable()) {
//        controller.setX(controller.getX() + 5);
//    } else if (field.getCell(controller.getX(), controller.getY() + 5).isPassable()) {
//        controller.setY(controller.getY() + 5);
//    }

//    GameEvent* event = field.getCell(controller.getX(),controller.getY()).getEvent();
//    if (event) {
//        event->triggerEvent();
//        field.getCell(controller.getX(),controller.getY()).setEvent(nullptr);
//    }
    controller.checkForEvent();

}