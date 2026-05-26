#include<iostream>
#include "FilteredLegoCatalog.h"

void FilteredLegoCatalog::filterByTheme(const Theme theme) {
   for (int i=0; i<sets.size(); ++i) {
     if (sets[i].getTheme()!=theme) {
         sets.erase(sets.begin()+i);
         --i;
     }
   }
}

void FilteredLegoCatalog::filterByPieces(const int maxPieces) {
    for (int i=0; i<sets.size(); ++i) {
        if (sets[i].getPieces()>maxPieces) {
            sets.erase(sets.begin()+i);
            --i;
        }
    }
}

void FilteredLegoCatalog::setLimit(const int limit) {
    while (sets.size()>limit) {
        sets.pop_back();
    }
}
