#ifndef STICKER_ALBUM_H
#define STICKER_ALBUM_H
#include <ostream>
#include <vector>
#include <iostream>
#include "Team.h"


class Album {
    std::vector<Team> teams;
public:
    Team& operator[](size_t);
    void getPage(size_t);
};



#endif //STICKER_ALBUM_H
