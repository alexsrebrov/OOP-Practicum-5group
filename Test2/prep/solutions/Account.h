#pragma once
#include "StarRepository.h"
#include "StarFilter.h"

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
        filters.push_back(StarFilter::create(filterType));
    }

    void addStar(const Star& star) {

        std::vector<std::string> failed;
        for (const auto& f : filters)
            if (!f->matches(star))
            {
                failed.push_back(f->describe());
            }

        if (!failed.empty()) {
            std::cout << "Problems: ";
            for (std::size_t i = 0; i < failed.size(); ++i)
            {
                std::cout << failed[i] << '\n';
            }
            return;
        }

        repo.add(std::move(star));
    }

    double accountRating() const 
    { 
        return repo.repoRating(); 
    }
};
