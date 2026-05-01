#ifndef GAMEHOUSE_GAMEHOUSE_H
#define GAMEHOUSE_GAMEHOUSE_H
#include <vector>
#include <memory>
#include "Player.h"
#include "Game.h"


class GameHouse {
    std::vector<std::shared_ptr<Player>> players;
    std::vector<Game> games;
    std::vector<double> profits;
public:
    void showGameHistory() const;
    void showPlayers() const;
    void play(const Game&);
};



#endif //GAMEHOUSE_GAMEHOUSE_H
