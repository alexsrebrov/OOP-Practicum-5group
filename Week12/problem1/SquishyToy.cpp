#include<iostream>
#include "SquishyToy.h"

SquishyToy::SquishyToy(const std::string &name, const double price, const std::string &manufacturer,
                       const bool isUsed) : Toy(name,price,manufacturer,isUsed){}

void SquishyToy::makeSound() const {
    std::cout<<"Squish!";
}

Toy * SquishyToy::clone() const {
    return new SquishyToy(*this);
}
