#pragma once
#include "Rarity.h"

class Star {
private:
    std::string name;
    Rarity rarity;
    unsigned trophies;
    unsigned level;

    static const unsigned MAX_LEVEL = 11;
public:

    Star(std::string& name, Rarity rarity, unsigned int trophies, unsigned int level);
    Star(std::string name, Rarity rarity, unsigned int trophies, unsigned int level);

    void setTrophies(unsigned trophies);

    void addTrophies(unsigned amount);

    unsigned getTrophies() const;
    unsigned getLevel() const;
    std::string getName() const;
    Rarity getRarity() const;
};
