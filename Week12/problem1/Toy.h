#pragma once
#include<string>
class Toy{
    std::string name;
    double price;
    std::string manufacturer;
    bool isUsed;
public:
    Toy() = delete;
    Toy(const std::string& name,const double price,const std::string& manufacturer,const bool isUsed);
    virtual ~Toy() = default;
    virtual Toy* clone() const=0;
    virtual void makeSound() const= 0;
    Toy& operator~();
    Toy& operator!();
};