#pragma once
#include "Computer_Peripheral.h"
#include "Mouse.h"
class Headphones: public Computer_Peripheral {
    Connectivity connectivity;
    bool hasMic;
public:
    Headphones(Connectivity connectivity,const bool hasMic,const std::string& model,const double price,const std::string& manufacturer);
};