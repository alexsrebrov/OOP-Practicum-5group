#pragma once
#include<string>
#include "Computer_Peripheral.h"
#include<vector>
enum class Language {
    EN,
    BG,
    ES,
    FR,
    DE
};
class Keyboard: public Computer_Peripheral {
    std::string colour;
    std::vector<Language> languages;

public:
    Keyboard(const std::string& colour,const std::vector<Language>& languages,const std::string& model,const double price,const std::string& manufacturer);
};