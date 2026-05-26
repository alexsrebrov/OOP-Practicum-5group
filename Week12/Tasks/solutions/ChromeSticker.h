#include "Sticker.h"

class ChromeSticker : public Sticker
{
private:
    static int serialNumberCounter;
    int serialNumber;
public:
    ChromeSticker(std::string& name);
    void printInfo() const override;
};