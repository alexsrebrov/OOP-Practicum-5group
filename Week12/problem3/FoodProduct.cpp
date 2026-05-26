#include "FoodProduct.h"
#include<iostream>
FoodProduct::FoodProduct(const double price, const std::string &manufacturer, const std::string &name, const int id,
    const double kilograms) : Product(price,manufacturer,name,id),kilograms(kilograms){}

Product * FoodProduct::clone() const {
    return new FoodProduct(*this);
}

std::string FoodProduct::getSize() const {
    return "Kilograms";
}
