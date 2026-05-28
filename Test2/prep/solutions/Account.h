#pragma once
#include "StarRepository.h"
#include "StarFilter.h"
#include "StarFilterFactory.h"

class Account {
private:
    StarRepository repo;
    std::vector<std::unique_ptr<StarFilter>> filters;

    void copyFrom(const Account& other)
    {
        this->repo = other.repo;

        for (const auto& filter : other.filters)
        {
            filters.push_back(filter->clone());
        }
    }

    void free()
    {
        filters.clear();
    }

public:
    Account() = default;

    Account(const Account& other)
    {
        copyFrom(other);
    }

    Account& operator=(const Account& other) {
        if (this != &other)
        {
            free();
            copyFrom(other);
        }
        return *this;
    }

    void addFilter(std::unique_ptr<StarFilter>& filter) 
    {
        filters.push_back(filter);
    }

    void addFilter(const std::string& filterType) 
    {
        filters.push_back(StarFilterFactory::create(filterType));
    }

    void unlockStar(const Star& star) 
    {
        bool success = true;
        
        for (const auto& f : filters)
        {
            if (!f->matches(star))
            {
                success = false;
                break;
            }
        }

        if (success) 
        {
            repo.add(star);
            return;
        }
        
        throw std::runtime_error("Star doesnt meet filters");
    }

    double accountRating() const 
    { 
        return repo.repoRating(); 
    }
};
