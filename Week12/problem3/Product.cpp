#include "Product.h"

Product::Product(const double price, const std::string &manufacturer, const std::string &name, const int id) : price(price),manufacturer(manufacturer),name(name),id(id){}

double Product::getPrice() const {
    return price;
}

int Product::getId() const {
    return id;
}

std::string Product::getName() const {
    return name;
}

std::string Product::getManufacturer() const {
    return manufacturer;
}

void Product::addLike() {
    likes++;
}

int Product::getLikes() const {
    return likes;
}
