#pragma once
#include "Command.h"
#include "Player.h"

class JumpCommand : public Command {
private:
    Player& player;
public:
    JumpCommand(Player& player) : player(player) {}
    
    void execute() override {
        player.jump();
    }
};