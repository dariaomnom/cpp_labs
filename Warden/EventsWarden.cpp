#include "EventsWarden.hpp"

EventsWarden::EventsWarden(PlayerController& controller, GameField& progressField) : controller(controller), progressField(progressField) {
    oldField = progressField;
}

bool EventsWarden::updateInfo() {
    int newX = controller.getX();
    int newY = controller.getY();
    GameEvent* old_event = oldField.getCell(newX, newY).getEvent();
    GameEvent* no_event = progressField.getCell(newX, newY).getEvent();


    if (dynamic_cast<GameEvent *>(old_event) && !dynamic_cast<GameEvent *>(no_event)) {
        oldField.getCell(newX, newY).setEvent(nullptr);
        return true;
    }
    return false;
}
