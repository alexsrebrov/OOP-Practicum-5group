#pragma once
#include "StarFilter.h"

class RarityFilter : public StarFilter {
    Rarity rarity;

public:
    RarityFilter(Rarity r): rarity(r) {
    }

    bool matches(const Star& s) const override 
    {
        return s.getRarity() == rarity;
    }

    std::string describe() const override {
        return "rarity==" + rarityToString(rarity);
    }

    std::unique_ptr<StarFilter> clone() const override {
        return std::make_unique<RarityFilter>(*this);
    }
};

