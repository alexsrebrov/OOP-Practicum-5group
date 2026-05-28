#pragma once
#include "Star.h"
#include <functional>

class StarRepository {
private:
    std::vector<Star> stars;

    bool contains(const std::string& name) const {
        for (auto& star : stars)
        {
            if (star.getName() == name)
            {
                return true;
            }
        }
        return false;
    }

public:
    void add(Star star) 
    {
        if (contains(star.getName()))
        {
            throw std::invalid_argument("Star " + star.getName() + " already exists in repository.");
        }
            
        stars.push_back(std::move(star));
    }

    void remove(std::function<bool(const Star&)> predicate) {
        std::remove_if(stars.begin(), stars.end(), predicate);
    }

    void sort(std::function<bool(const Star&, const Star&)> comparator) {
        size_t n = stars.size();

        for (int i = 0; i < n - 1; i++) {
            int minIdx = i;

            for (int j = i + 1; j < n; j++) {
                if (comparator(stars[minIdx], stars[j])) {
                    minIdx = j;
                }
            }

            if (minIdx != i) {
                std::swap(stars[i], stars[minIdx]);
            }
        }
    }

    double repoRating() const {
        int result = 0;

        for (auto& star : stars)
        {
            result += star.getTrophies();
        }

        return result;
    }
};

