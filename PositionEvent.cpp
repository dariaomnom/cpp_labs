#include "PositionEvent.hpp"

PositionEvent::PositionEvent(Player &player, PlayerController &controller, GameField &field) : FieldEvent(player,
                                                                                                          controller,
                                                                                                          field) {}

void PositionEvent::triggerEvent() {
    // one-off teleport else remove the next line
    field.getCell(controller.getX(), controller.getY()).setEvent(nullptr);

    int x = controller.getX();
    int y = controller.getY();
    int newX = x + 5 < field.getSize().first ? x + 5 : field.getSize().first - 1;
    int newY = y + 5 < field.getSize().second ? y + 5 : field.getSize().second - 1;

    if (field.getCell(newX, newY).isPassable()) {
        controller.setX(newX);
        controller.setY(newY);
    } else if (field.getCell(newX, y).isPassable()) {
        controller.setX(newX);
    } else if (field.getCell(x, newY).isPassable()) {
        controller.setY(newY);
    }

    controller.checkForEvent();
}