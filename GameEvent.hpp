#ifndef GAMEEVENT_HPP
#define GAMEEVENT_HPP

class Player;

class GameEvent {
public:
//    explicit GameEvent(Player& player);
    virtual ~GameEvent() = default;
    virtual void triggerEvent(Player& player) = 0;
};

#endif