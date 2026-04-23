#include "Sticker.h"
#include <iostream>
#pragma warning (disable: 4996)

int Sticker::counter = 0;
bool operator==(const Sticker& lhs, const Sticker& rhs) {
    return lhs.id == rhs.id;
}

bool operator<(const Sticker& lhs, const Sticker& rhs) {
    return lhs.id < rhs.id;
}

void Sticker::copyFrom(const Sticker& other) {
    this -> name = new char[strlen(other.name) + 1];
    strcpy(this -> name, other.name);
    this -> id = counter++;
    this -> rarity = other.rarity;
    this -> rating = other.rating;
}

void Sticker::moveFrom(Sticker&& other) {
    this -> name = other.name;
    other.name = nullptr;
    this -> id = counter++;
    this -> rarity = other.rarity;
    this -> rating = other.rating;
}

void Sticker::free() {
    delete[] name;
    name = nullptr;
}

Sticker::Sticker() : id(counter++), name(new char[1]{'\0'}), rating(0), rarity(Rarity::Standard) {}

Sticker::Sticker(const char* name, const int rating, const Rarity rarity) : id(counter++), rating(rating), rarity(rarity) {
    this -> name = new char[strlen(name) + 1];
    strcpy(this -> name, name);
}

Sticker::Sticker(const Sticker& other) {
    copyFrom(other);
}

Sticker& Sticker::operator=(const Sticker& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

Sticker::~Sticker() {
    free();
}

Sticker::Sticker(Sticker&& other) {
    moveFrom(std::move(other));
}

Sticker& Sticker::operator=(Sticker&& other) {
    if (this != &other) {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

int Sticker::getRating() const {
    return rating;
}

const char* Sticker::getName() const {
    return name;
}
