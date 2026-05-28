#include "Star.h"

Star::Star(std::string& name, Rarity rarity, unsigned int trophies, unsigned int level)
    : name(name), rarity(rarity), level(level)
{
    setTrophies(trophies);
}

Star::Star(std::string name, Rarity rarity, unsigned int trophies, unsigned int level)
    : name(std::move(name)), rarity(rarity), level(level)
{
    setTrophies(trophies);
}

void Star::setTrophies(unsigned trophies)
{
    if (level > MAX_LEVEL)
    {
        throw std::invalid_argument("Level must be <= " + std::to_string(MAX_LEVEL));
    }

    this->trophies = trophies;
}

void Star::addTrophies(unsigned amount)
{
    trophies += amount;
}

unsigned Star::getTrophies() const
{
    return trophies;
}

unsigned Star::getLevel() const
{
    return level;
}

std::string Star::getName() const
{
    return name;
}

Rarity Star::getRarity() const
{
    return rarity;
}