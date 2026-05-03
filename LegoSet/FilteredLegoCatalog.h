#ifndef LEGOSET_FILTEREDLEGOCATALOG_H
#define LEGOSET_FILTEREDLEGOCATALOG_H
#include "LegoCatalog.h"


class FilteredLegoCatalog : public LegoCatalog {
public:
    FilteredLegoCatalog();
    void filter(const std::string& criteria);
    void filter(int criteria);
    void limit(int n);
};


#endif //LEGOSET_FILTEREDLEGOCATALOG_H
