#ifndef MONITORHP_CPP
#define MONITORHP_CPP

#include "MonitorPlayerStats.h"

MonitorPlayerStats::MonitorPlayerStats(Controller &controller) : controller(controller) {
    prevHP = controller.getPlayerHP();
    prevMasculinity = controller.getPlayerMasculinity();
}

bool MonitorPlayerStats::update() {
    if (controller.getPlayerHP() != prevHP || controller.getPlayerMasculinity() != prevMasculinity) {
        prevHP = controller.getPlayerHP();
        prevMasculinity = controller.getPlayerMasculinity();
        return true;
    }
    return false;
}

#endif
