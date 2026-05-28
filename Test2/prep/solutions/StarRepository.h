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
        std::erase_if(stars, predicate);

        /* ако не сте сигурни как и какво се използва с вградените функции можете да направите един for цикъл
        std::vector<Star> kept;
        for (auto& star : stars) 
        {
            if (!predicate(star))
            {
                kept.push_back(star);
            }
        }

        с std::move копирането става малко по-оптимално (kept така или иначе ще бъде изтрито в края на метода)
        stars = std::move(kept);
        */
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

    const Star& findByName(const std::string& name) const {
        for (auto& star : stars)
        {
            if (star.getName() == name)
            {
                return star;
            }
        }
        throw std::runtime_error("There isnt a star with this name");
    }

    Star& findByName(const std::string& name) {
        for (auto& star : stars)
        {
            if (star.getName() == name)
            {
                return star;
            }
        }
        throw std::runtime_error("There isnt a star with this name");
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

