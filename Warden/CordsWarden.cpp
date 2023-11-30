#include "CordsWarden.hpp"

CordsWarden::CordsWarden(PlayerController &controller) : controller(controller) {
    oldX = controller.getX();
    oldY = controller.getY();
}

bool CordsWarden::updateInfo() {
    int newX = controller.getX();
    int newY = controller.getY();

    if (newX != oldX || newY != oldY) {
        oldX = newX;
        oldY = newY;
        return true;
    }
    return false;
}
