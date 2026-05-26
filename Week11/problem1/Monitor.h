#pragma once
#include<string>
#include "Computer_Peripheral.h"
class Monitor : public Computer_Peripheral {
    int refreshRate;
    double size;

public:
    Monitor(const int refreshRate,const double size,const std::string& model,const double price,const std::string& manufacturer);
};