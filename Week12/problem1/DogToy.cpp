#include "DogToy.h"
#include<iostream>
DogToy::DogToy(const std::string &name, const double price, const std::string &manufacturer, const bool isUsed) : Toy(name,price,manufacturer,isUsed){}

void DogToy::makeSound() const {
    std::cout<<"Bark Bark!"<<std::endl;
}

Toy * DogToy::clone() const {
    return new DogToy(*this);
}
