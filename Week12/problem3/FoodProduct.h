#pragma once
#include "Product.h"
class FoodProduct : public Product {
    double kilograms;
public:
    FoodProduct(const double price,const std::string& manufacturer,const std::string& name,const int id,const double kilograms);
    Product* clone() const override;
    std::string getSize() const override;
};


