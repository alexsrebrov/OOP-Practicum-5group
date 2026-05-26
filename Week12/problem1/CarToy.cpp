#include<iostream>
#include "CarToy.h"

CarToy::CarToy(const std::string &name, const double price, const std::string &manufacturer, const bool isUsed) : Toy(name,price,manufacturer,isUsed){}

void CarToy::makeSound() const {
    std::cout<<"Beep!";
}

Toy * CarToy::clone() const {
    return new CarToy(*this);
}
