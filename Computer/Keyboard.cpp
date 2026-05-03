#include "Keyboard.h"

Keyboard::Keyboard(std::string color, Language l) {
    this -> color = std::move(color);
    languages.push_back(l);
}

Keyboard::Keyboard(std::string color, Language l1, Language l2) {
    this -> color = std::move(color);
    languages.push_back(l1);
    languages.push_back(l2);
}
