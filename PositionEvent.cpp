#include "PositionEvent.hpp"

PositionEvent::PositionEvent(Player &player, PlayerController &controller, GameField &field) : FieldEvent(player, controller, field){}

void PositionEvent::triggerEvent() {
    if (field.getCell(controller.getX() + 5, controller.getY() + 5).isPassable()) {
        controller.setX(controller.getX() + 5);
        controller.setY(controller.getY() + 5);
    } else if (field.getCell(controller.getX() + 5, controller.getY()).isPassable()) {
        controller.setX(controller.getX() + 5);
    } else if (field.getCell(controller.getX(), controller.getY() + 5).isPassable()) {
        controller.setY(controller.getY() + 5);
    }
    GameEvent* event = field.getCell(controller.getX(),controller.getY()).getEvent();
    if (event) {
        event->triggerEvent();
    }
}