#include "DrinkProduct.h"
#include<iostream>
DrinkProduct::DrinkProduct(const double price, const std::string &manufacturer, const std::string &name, const int id,
    const double litres) : Product(price,manufacturer,name,id),litres(litres){}

Product * DrinkProduct::clone() const {
    return new DrinkProduct(*this);
}

std::string DrinkProduct::getSize() const {
    return "Litres";
}