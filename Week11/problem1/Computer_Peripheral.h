#pragma once
#include<string>
class Computer_Peripheral {
protected:
  std::string model;
  double price;
  std::string manufacturer;
public:
  Computer_Peripheral(const std::string& model,const double price,const std::string& manufacturer);
  double getPrice() const;
  std::string& getModel();
  std::string& getManufacturer();
  void setPrice(const double price);
};