#include "StarFilter.h"
#include "MinLevelFilter.h"
#include "MinTrophiesFilter.h"
#include "RarityFilter.h"

std::unique_ptr<StarFilter> StarFilter::create(const std::string& type) {
    if (type == "min_trophies")
    {
        unsigned param;
        std::cin >> param;
        return std::make_unique<MinTrophiesFilter>(param);
    }
    else if (type == "min_level")
    {
        unsigned param;
        std::cin >> param;
        return std::make_unique<MinLevelFilter>(param);
    }
    else if (type == "rarity")
    {
        std::string param;
        std::cin >> param;
        return std::make_unique<RarityFilter>(rarityFromString(param));
    }
    else
    {
        throw std::invalid_argument("Unknown filter type: " + type);
    }
}