#pragma once
#include "StarFilter.h"

class MinTrophiesFilter : public StarFilter {
    unsigned minTrophies;
public:
    MinTrophiesFilter(unsigned minTrophies) : minTrophies(minTrophies) {}
    
    bool matches(const Star& s) const override 
    { 
        return s.getTrophies() >= minTrophies; 
    }

    std::string describe() const override 
    {
        return "min_trophies(" + std::to_string(minTrophies) + ")";
    }

    std::unique_ptr<StarFilter> clone() const override 
    {
        return std::make_unique<MinTrophiesFilter>(*this);
    }
};
