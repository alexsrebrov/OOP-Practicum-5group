#pragma once
#include "Toy.h"
class CarToy: public Toy {
public:
    CarToy(const std::string& name,const double price,const std::string& manufacturer,const bool isUsed);
    void makeSound() const override;
    Toy* clone() const override;
};