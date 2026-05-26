#pragma once
#include "Computer_Peripheral.h"
enum class Connectivity {
    CABLE,
    WIRELESS
};
class Mouse : public Computer_Peripheral{
  Connectivity connectivity;

public:
    Mouse(Connectivity connectivity,const std::string& model,const double price,const std::string& manufacturer);
};