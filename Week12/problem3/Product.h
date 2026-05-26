#pragma once
#include<string>
class Product {
    double price;
    std::string manufacturer;
    std::string name;
    int id;
    int likes=0;
public:
    Product(const double price,const std::string& manufacturer,const std::string& name,const int id);
    virtual std::string getSize() const = 0;
    virtual Product* clone() const=0;
    virtual ~Product()=default;
    double getPrice() const;
    int getId() const;
    std::string getName() const;
    std::string getManufacturer() const;
    void addLike();
    int getLikes() const;
};


