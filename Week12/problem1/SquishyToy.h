#pragma once
#include "Toy.h"
class SquishyToy : public Toy {
public:
    SquishyToy(const std::string& name,const double price,const std::string& manufacturer,const bool isUsed);
    void makeSound() const override;
    Toy* clone() const override;
};