#pragma once
#include "Toy.h"
class DogToy: public Toy {
public:
    DogToy(const std::string& name,const double price,const std::string& manufacturer,const bool isUsed);
    void makeSound() const override;
    Toy* clone() const override;
};