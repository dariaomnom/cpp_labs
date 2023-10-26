#ifndef LABS_GAMEEVENT_HPP
#define LABS_GAMEEVENT_HPP

class GameEvent{

public:
    virtual void triggerEvent() = 0;
    virtual ~GameEvent() = default;
};
#endif
