#pragma once
#include "Team.h"
#include<vector>
class Album {
    std::vector<Team> teams;
public:
    Album();
    Album(const std::vector<Team>& teams);
    Team& operator[](const int index);
    void getPage(size_t page) const;
};