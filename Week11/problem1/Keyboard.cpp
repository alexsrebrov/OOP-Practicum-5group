#include "Keyboard.h"

Keyboard::Keyboard(const std::string &colour,const std::vector<Language>& languages, const std::string &model, const double price,
    const std::string &manufacturer) : colour(colour),Computer_Peripheral(model,price,manufacturer) {
    if (languages.size()==0 || languages.size()>2) {
        //exception
    }
    this->languages=languages;
}
