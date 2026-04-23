#include "Team.h"

#include <ostream>

void Team::free() {
    delete[] players;
    players = nullptr;
    delete[] managerName;
    managerName = nullptr;
}

void Team::copyFrom(const Team& other) {
    this -> players = new Sticker[other.playerCount];
    this -> playerCount = other.playerCount;
    for (int i = 0; i < other.playerCount; i++) {
        this -> players[i] = other.players[i];
    }
    this -> managerName = new char[strlen(other.managerName) + 1];
    strcpy(this -> managerName, other.managerName);
    this -> stadium = other.stadium;
}

void Team::moveFrom(Team&& other) {
    this -> players = other.players;
    other. players = nullptr;
    this -> playerCount = other.playerCount;
    other.playerCount = 0;
    this -> managerName = other.managerName;
    other.managerName = nullptr;
    this -> stadium = std::move(other.stadium);
}

double Team::averageRating() const {
    if (playerCount) {
        double result = 0;
        for (int i = 0; i < playerCount; i++) {
            result += players[i].getRating();
        }
        return result / playerCount;
    }
    return 0;
}

Team::Team() : players(nullptr), playerCount(0), managerName(nullptr) {}

Team::~Team() {
    free();
}

Team::Team(const Team& other) {
    copyFrom(other);
}

Team& Team::operator=(const Team& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

Team::Team(Team&& other) {
    moveFrom(std::move(other));
}

Team & Team::operator=(Team&& other) {
    if (this != &other) {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

std::ostream & operator<<(std::ostream &os, const Team &team) {
    os << "Team players: " << std::endl;
    for (int i = 0; i < team.playerCount; i++) {
        os << team.players[i].getName() << std::endl;
    }
    os << "Player count: " << team.playerCount << std::endl;
    os << "Manager name: " << team.managerName << std::endl;
    os << "Plays on: " << team.stadium << std::endl;
    return os;
}
