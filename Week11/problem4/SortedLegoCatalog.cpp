#include "SortedLegoCatalog.h"
#include<iostream>
void SortedLegoCatalog::sortByPieces() {
    for (int i=0; i<sets.size(); ++i) {
        for (int j=0; j<sets.size()-i-1; ++j) {
            if (sets[j]>sets[j+1]) {
                std::swap(sets[j],sets[j+1]);
            }
        }
    }
}
