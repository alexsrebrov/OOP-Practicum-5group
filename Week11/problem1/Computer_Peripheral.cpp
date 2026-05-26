#include "Computer_Peripheral.h"

Computer_Peripheral::Computer_Peripheral(const std::string &model, const double price, const std::string &manufacturer) : model(model),price(price),manufacturer(manufacturer){}

double Computer_Peripheral::getPrice() const {
    return price;
}

std::string & Computer_Peripheral::getModel() {
    return model;
}

std::string & Computer_Peripheral::getManufacturer() {
    return manufacturer;
}

void Computer_Peripheral::setPrice(const double price) {
    this->price=price;
}
