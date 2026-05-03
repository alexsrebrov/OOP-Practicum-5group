#ifndef COMPUTER_MONITOR_H
#define COMPUTER_MONITOR_H
#include <iostream>

#include "ComputerPeripheral.h"

class Monitor : public ComputerPeripheral {
    size_t refreshRate;
    size_t size;
};


#endif //COMPUTER_MONITOR_H
