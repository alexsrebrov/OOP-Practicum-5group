#pragma once
#include "Command.h"
#include "Player.h"

class MoveCommand : public Command {
private:
    int x, y;
    Player& player;
public:
    MoveCommand(Player& player, int x, int y) : player(player), x(x), y(y) {}
    
    void execute() override {
        player.move(x, y);
    }
};