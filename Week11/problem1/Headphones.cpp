
#include "Headphones.h"

Headphones::Headphones(Connectivity connectivity, const bool hasMic, const std::string &model, const double price,
    const std::string &manufacturer) : connectivity(connectivity),hasMic(hasMic),Computer_Peripheral(model,price,manufacturer){}
