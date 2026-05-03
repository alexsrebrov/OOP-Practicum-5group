#ifndef COMPUTER_COMPUTERPERIPHERAL_H
#define COMPUTER_COMPUTERPERIPHERAL_H
#include <string>


class ComputerPeripheral {
    std::string model;
    double price;
    std::string manufacturer;
public:
    double getPrice() const;
    void setPrice(double price);
};


#endif //COMPUTER_COMPUTERPERIPHERAL_H
