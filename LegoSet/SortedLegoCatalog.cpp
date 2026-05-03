#include "SortedLegoCatalog.h"

#include <algorithm>

void SortedLegoCatalog::sort() {
    std::sort(sets.begin(), sets.end());
}
