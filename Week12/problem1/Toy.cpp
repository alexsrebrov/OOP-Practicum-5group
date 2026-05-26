
#include "Toy.h"

Toy::Toy(const std::string &name, const double price, const std::string &manufacturer, const bool isUsed) : name(name),price(price),manufacturer(manufacturer),isUsed(isUsed){}

Toy & Toy::operator~() {
    isUsed=true;
    return *this;
}

Toy & Toy::operator!() {
    isUsed=false;
    return *this;
}
