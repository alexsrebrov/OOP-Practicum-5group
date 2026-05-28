#pragma once
#include "Star.h"

class StarFilter {
public:
    virtual ~StarFilter() = default;

    virtual bool matches(const Star& s) const = 0;
    virtual std::unique_ptr<StarFilter> clone() const = 0;
    
    virtual std::string describe() const = 0;

    static std::unique_ptr<StarFilter> create(const std::string& type);
};

