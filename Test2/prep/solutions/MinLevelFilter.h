#pragma once
#include "StarFilter.h"

class MinLevelFilter : public StarFilter {
    unsigned int minLevel;
public:
    MinLevelFilter(unsigned int minLevel) : minLevel(minLevel) {}
    bool matches(const Star& s) const override 
    { 
        return s.getLevel() >= minLevel;
    }

    std::string describe() const override {
        return "min_level(" + std::to_string(minLevel) + ")";
    }

    std::unique_ptr<StarFilter> clone() const override {
        return std::make_unique<MinLevelFilter>(*this);
    }
};