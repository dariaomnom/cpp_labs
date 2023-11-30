

#ifndef PLAYERWARDEN_HPP
#define PLAYERWARDEN_HPP


#include "Warden.hpp"
#include "../PlayerController.hpp"

class PlayerWarden : public Warden{
private:
    Controller& controller;
    int prevHP;
    int prevMasculinity;
public:
    MonitorPlayerStats(Controller& controller);
    bool update() override;
};

#endif



#endif //LABS_PLAYERWARDEN_HPP
