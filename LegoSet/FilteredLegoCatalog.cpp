#include "FilteredLegoCatalog.h"
#include "LegoSet.h"
#include <set>

FilteredLegoCatalog::FilteredLegoCatalog() : LegoCatalog() {}

void FilteredLegoCatalog::filter(const std::string& criteria) {
    std::erase_if(sets, [criteria](LegoSet& set) {
        return set.getName() != criteria && set.getTheme() != criteria;
    });
}

void FilteredLegoCatalog::filter(int criteria) {
    std::erase_if(sets, [criteria](LegoSet& set) {
        return set.getCode() != criteria && set.getPieceCount() != criteria;
    });
}

void FilteredLegoCatalog::limit(int n) {
    sets.resize(n);
}
