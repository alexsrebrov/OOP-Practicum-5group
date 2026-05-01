#include "Game.h"

Type Game::getType() const{
    return this -> type;
}

std::string Game::getWinnerName() const {
    return this -> winnerName;
}

int Game::getWinnerId() const {
    return this -> winnerId;
}

std::vector<std::pair<Player, double>> Game::getPlayers() const {
    return players;
}
