#pragma once
#include "Product.h"
class DrinkProduct : public Product {
    double litres;
public:
    DrinkProduct(const double price,const std::string& manufacturer,const std::string& name,const int id,const double litres);
    Product* clone() const override;
    std::string getSize() const override;
};