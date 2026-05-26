#include "Sticker.h"
#include <iostream>

unsigned Sticker::counter = 0;

Sticker::Sticker(std::string& name) : name(name)
{
    number = counter++;
}

void Sticker::printInfo() const
{
    std::cout << number << " " << name << std::endl;
}

bool Sticker::operator==(unsigned num) const
{
    return this->number == num;
}