#include<iostream>
#include "Album.h"

Album::Album() = default;

Album::Album(const std::vector<Team> &teams) {
    this->teams=teams;
}

Team & Album::operator[](const int index) {
    if (index>=teams.size()) {
        //exception
    }
    return teams[index];
}

void Album::getPage(size_t page) const{
    if (page>=teams.size()) {
        //exception
    }
    std::cout<<teams[page];
}
