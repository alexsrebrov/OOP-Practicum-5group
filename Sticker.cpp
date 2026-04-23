#include "Sticker.h"
#include<iostream>
void Sticker::copyFrom(const Sticker& other) {
    size_t nameLen=strlen(other.name);
    name=new char[nameLen+1];
    strcpy(name,other.name);
    id=other.id;
    rating=other.rating;
    rarity=other.rarity;
}

void Sticker::moveFrom(Sticker&& other) {
    name=other.name;
    other.name=nullptr;
    id=other.id;
    other.id=0;
    rating=other.rating;
    other.rating=0;
    rarity=other.rarity;
    other.rarity=Rarity::STANDART;
}

void Sticker::free() {
    delete[] name;
    name=nullptr;
    id=0;
    rating=0;
    rarity=Rarity::STANDART;
}

Sticker::Sticker() : id(0),rating(0),rarity(Rarity::STANDART){
 name=new char[1];
 strcpy(name,"");
}

Sticker::Sticker(const int id, const char *name, const unsigned rating, const Rarity rarity) : id(id),rating(rating), rarity(rarity) {
    this->name = new char[strlen(name)+1];
    strcpy(this->name,name);
}

Sticker::Sticker(const Sticker &other) {
    copyFrom(other);
}

Sticker & Sticker::operator=(const Sticker &other) {
    if (this!=&other) {
        free();
        copyFrom(other);
    }
    return *this;
}

Sticker::Sticker(Sticker &&other) noexcept {
    moveFrom(std::move(other));
}

Sticker & Sticker::operator=(Sticker &&other) noexcept {
    if (this!=&other) {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

Sticker::~Sticker() {
    free();
}

bool Sticker::operator==(const Sticker &other) const  {
    return id==other.id;
}

bool Sticker::operator>(const Sticker &other) const {
    return id>other.id;
}

unsigned Sticker::getRating() const {
    return rating;
}
