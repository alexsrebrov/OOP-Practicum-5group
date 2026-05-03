#ifndef COMPUTER_KEYBOARD_H
#define COMPUTER_KEYBOARD_H
#include <string>
#include <vector>

#include "ComputerPeripheral.h"

enum class Language {
    EN, BG, ES, FR, DE
};
class Keyboard : public ComputerPeripheral {
    std::string color;
    std::vector<Language> languages;
public:
    Keyboard(std::string color, Language l);
    Keyboard(std::string color, Language l1, Language l2);
};

#endif //COMPUTER_KEYBOARD_H
