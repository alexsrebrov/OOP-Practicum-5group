#include "LegoSet.h"
#include<iostream>
int LegoSet::counter=1;

LegoSet::LegoSet(const std::string &name, const int pieceCount, const Theme theme) : name(name),pieceCount(pieceCount),id(counter++),theme(theme){}

Theme LegoSet::getTheme() const {
    return theme;
}

int LegoSet::getPieces() const {
    return pieceCount;
}

std::strong_ordering operator<=>(const LegoSet &lhs, const LegoSet &rhs) {
    return lhs.pieceCount<=>rhs.pieceCount;
}

bool operator==(const LegoSet &lhs, const LegoSet &rhs) {
    return lhs.pieceCount==rhs.pieceCount;
}

std::ostream & operator<<(std::ostream &os, const LegoSet &set) {
    os<<"Name:"<<set.name<<" PieceCount:"<<set.pieceCount<<" ID:"<<set.id<<" Theme: ";
    switch (set.theme) {
        case Theme::STAR_WARS : os<<"Star Wars"<<std::endl; return os;
        case Theme::NINJAGO : os<<"Ninjago"<<std::endl; return os;
        case Theme::CITY : os<<"City"<<std::endl; return os;
    }
}
