#pragma once
#include<vector>
#include "LegoSet.h"
class LegoCatalog {
protected:
    std::vector<LegoSet> sets;
public:
    LegoCatalog() = default;
    LegoCatalog(const std::vector<LegoSet>& sets);
    void addSet(const LegoSet& set);
    void removeSet(LegoSet& set);
    friend std::ostream& operator<<(std::ostream& os,const LegoCatalog& catalog);
};