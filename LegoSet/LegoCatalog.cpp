#include "LegoCatalog.h"
#include <iostream>

void LegoCatalog::add(LegoSet set) {
    this->sets.push_back(std::move(set));
}

void LegoCatalog::remove(const LegoSet& set) {
    erase_if(sets, [set](const LegoSet& s) { return s == set; });
}

std::ostream & operator<<(std::ostream &os, const LegoCatalog &catalog) {
    for (const LegoSet& set : catalog.sets) {
        os << set << std::endl;
    }
    return os;
}
