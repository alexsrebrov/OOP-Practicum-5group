#include "ChromeSticker.h"
#include <iostream>

int ChromeSticker::serialNumberCounter = 0;

ChromeSticker::ChromeSticker(std::string& name) : Sticker(name)
{
    serialNumber = serialNumberCounter++;
}

void ChromeSticker::printInfo() const
{
    Sticker::printInfo();
    std::cout << "Serial Number: " << serialNumber << std::endl;
}