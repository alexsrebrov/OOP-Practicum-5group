#include "MoveCommand.h"
#include "ShootCommand.h"
#include "JumpCommand.h"
#include "InvalidCommand.h"
#include <memory>
#include <vector>


class CommandFactory {
public:
    static std::unique_ptr<Command> create(Player& player, const std::vector<std::string>& t) {
        
        if (t.empty())  throw InvalidCommand("Empty command");


        if (t[0] == "move") {
            if (t.size() != 3)  throw InvalidCommand("Move command requires 2 parameters");

            return std::make_unique<MoveCommand>(player, std::stoi(t[1]), std::stoi(t[2]));
        }

        if (t[0] == "shoot") {
            if (t.size() != 2)  throw InvalidCommand("Shoot command requires 1 parameter");

            return std::make_unique<ShootCommand>(player, std::stoi(t[1]));
        }
        
        if (t[0] == "jump") {
            if (t.size() != 1)  throw InvalidCommand("Jump command requires no parameters");

            return std::make_unique<JumpCommand>(player);
        }

        throw InvalidCommand();
    }
};