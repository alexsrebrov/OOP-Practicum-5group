#include "Monitor.h"
Monitor::Monitor(const int refreshRate, const double size, const std::string &model, const double price,
    const std::string &manufacturer) : refreshRate(refreshRate),size(size),Computer_Peripheral(model,price,manufacturer){}
