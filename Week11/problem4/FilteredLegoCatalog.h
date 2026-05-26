#pragma once
#include "LegoCatalog.h"
class FilteredLegoCatalog : public LegoCatalog {
public:
    void filterByTheme(const Theme theme);
    void filterByPieces(const int maxPieces);
    void setLimit(const int limit);
};