#ifndef LEGOSET_LEGOCATALOG_H
#define LEGOSET_LEGOCATALOG_H
#include <vector>

#include "LegoSet.h"

class LegoCatalog {
protected:
    std::vector<LegoSet> sets;
public:
    void add(LegoSet set);
    void remove(const LegoSet& set);
    friend std::ostream &operator<<(std::ostream &os, const LegoCatalog &catalog);
};


#endif //LEGOSET_LEGOCATALOG_H
