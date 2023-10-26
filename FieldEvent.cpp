#include "FieldEvent.hpp"

FieldEvent::FieldEvent(Player& player, PlayerController& controller, GameField& field)
: player(player), controller(controller), field(field) {}