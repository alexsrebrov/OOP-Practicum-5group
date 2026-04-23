#ifndef TEAM_TEAM_H
#define TEAM_TEAM_H
#include "Sticker.h"
#include <string>

class Team {
    Sticker* players;
    int playerCount;
    char* managerName;
    std::string stadium;
    void free();
    void copyFrom(const Team&);
    void moveFrom(Team&&);
public:
    double averageRating() const;
    friend std::ostream& operator<<(std::ostream&, const Team&);
    Team();
    ~Team();
    Team(const Team&);
    Team& operator=(const Team&);
    Team(Team&& team);
    Team& operator=(Team&&);
};



#endif //TEAM_TEAM_H
