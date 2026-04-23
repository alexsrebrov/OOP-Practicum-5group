#include<iostream>
#include "Team.h"
#include "Sticker.h"
void Team::free() {
    delete[] mngName;
    mngName=nullptr;
    size=0;
    stadium="";
}

void Team::copyFrom(const Team &other) {
    size=other.size;
    for (int i=0; i<size; ++i) {
        players[i]=other.players[i];
    }
    size_t managerLen=strlen(other.mngName);
    mngName=new char[managerLen+1];
    strcpy(mngName,other.mngName);
    stadium=other.stadium;
}

void Team::moveFrom(Team &&other) {
    size=other.size;
    for (int i=0; i<size; ++i) {
        players[i]=std::move(other.players[i]);
    }
    other.size=0;
    mngName=other.mngName;
    other.mngName=nullptr;
    stadium=std::move(other.stadium);
}

Team::Team() : size(0), stadium(""){
    mngName=new char[1];
    strcpy(mngName,"");
}

Team::Team(const Sticker *players,const size_t size,const char *mngName, const std::string &stadium) : stadium(stadium){
    if (size>=11) {
        this->size=11;
    }
    else {
        this->size=size;
    }
    for (int i=0; i<this->size; ++i) {
        this->players[i]=players[i];
    }
    this->mngName=new char[strlen(mngName)+1];
    strcpy(this->mngName,mngName);
}

Team::Team(const Team &other) {
    copyFrom(other);
}

Team & Team::operator=(const Team &other) {
    if (this!=&other) {
        free();
        copyFrom(other);
    }
    return *this;
}

Team::Team(Team &&other) noexcept {
    moveFrom(std::move(other));
}

Team & Team::operator=(Team &&other) noexcept {
    if (this!=&other) {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

Team::~Team() {
    free();
}

double Team::avrgRating() const {
    double sum=0;
    for (int i=0; i<size; ++i) {
        sum+=players[i].getRating();
    }
    return sum/size;
}
