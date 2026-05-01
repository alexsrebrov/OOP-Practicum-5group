#ifndef GAMEHOUSE_GAME_H
#define GAMEHOUSE_GAME_H
#include <vector>

#include "Player.h"


enum class Type {
    Poker, Blackjack, Slots
};
class Game {
    Type type;
    std::vector<std::pair<Player, double>> players;
    std::string winnerName;
    int winnerId;
public:
    Type getType() const;
    std::string getWinnerName() const;
    int getWinnerId() const;
    std::vector<std::pair<Player, double>> getPlayers() const;
};



#endif //GAMEHOUSE_GAME_H
