#pragma once
#include "Command.h"
#include "Player.h"

class ShootCommand : public Command {
private:
    int target;
    Player& player;
public:
    ShootCommand(Player& player, int target) : player(player), target(target) {}
    
    void execute() override {
        player.shoot(target);
    }
};