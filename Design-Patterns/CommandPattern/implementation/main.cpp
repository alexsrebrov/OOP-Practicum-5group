#include <iostream>
#include <sstream>
#include "Player.h"
#include "CommandFactory.h"

std::vector<std::string> split(const std::string& str) {
    std::stringstream ss(str);
    std::vector<std::string> out;
    std::string w;

    while (ss >> w)
        out.push_back(w);

    return out;
}

int main() {
    Player player;

    while (true) {
        std::string line;
        std::cout << "> ";
        std::getline(std::cin, line);

        std::vector<std::string> tokens = split(line);

        if (!tokens.empty() && tokens[0] == "exit") {
            player.printStatus();
            break;
        }

        try {
            CommandFactory::create(player, tokens) -> execute();
        }
        catch (const InvalidCommand& e) {
            std::cout << "Error: " << e.what() << "\n";
        }

        // See the player's status after each command
        std::cout << "=====================\n";
        player.printStatus();
        std::cout << "=====================\n\n";
    }
}