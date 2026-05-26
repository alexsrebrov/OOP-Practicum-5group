#include<iostream>
#include "LegoCatalog.h"

LegoCatalog::LegoCatalog(const std::vector<LegoSet> &sets) : sets(sets){}

void LegoCatalog::addSet(const LegoSet &set) {
    sets.push_back(set);
}

void LegoCatalog::removeSet(LegoSet &set) {
    for (int i=0; i<sets.size(); ++i) {
        if (sets[i]==set) {
            sets.erase(sets.begin()+i);
            return;
        }
    }
}

std::ostream & operator<<(std::ostream &os, const LegoCatalog &catalog) {
    os<<"Catalog:"<<std::endl;
    for (int i=0; i<catalog.sets.size(); ++i) {
       os<<catalog.sets[i];
    }
    os<<std::endl;
    return os;
}
