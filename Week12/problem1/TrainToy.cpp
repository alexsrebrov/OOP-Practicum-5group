
#include<iostream>
#include "TrainToy.h"

TrainToy::TrainToy(const std::string &name, const double price, const std::string &manufacturer, const bool isUsed) : Toy(name,price,manufacturer,isUsed){}

void TrainToy::makeSound() const {
    std::cout<<"Train noises!";
}

Toy * TrainToy::clone() const {
    return new TrainToy(*this);
}
