#ifndef PAIR_MAP_H
#define PAIR_MAP_H
#include <iostream>

#include "Pair.hpp"

template <typename K, typename V> class Map {
    Pair<K, V>* pairs;
    size_t size;
    size_t capacity;
    void resize();
public:
    Map<K, V>();
    ~Map<K, V>();
    void add(const K& key, const V& value);
    void add(const K& key, V&& value);
    bool remove(const K& key);
    bool contains(const K& key) const;
    const V& operator[](const K& key) const;
    V& operator[](const K& key);
    size_t getSize() const;
    size_t getCapacity() const;
    bool empty() const;
};

template<typename K, typename V>
void Map<K, V>::resize() {
    if (size > 0) {
        auto* newPairs = new Pair<K, V>[capacity * 2];
        for (size_t i = 0; i < size; i++) {
            newPairs[i].set(pairs[i].getFirst(), pairs[i].getSecond());
        }
        delete[] pairs;
        pairs = newPairs;
        capacity *= 2;
    }
    else {
        pairs = new Pair<K, V>[1];
        capacity = 1;
    }
}

template<typename K, typename V>
Map<K, V>::Map() : pairs(nullptr), size(0), capacity(0) {}

template<typename K, typename V>
Map<K, V>::~Map() {
    delete[] pairs;
}

template<typename K, typename V>
void Map<K, V>::add(const K &key, const V &value) {
    for (size_t i = 0; i < size; i++) {
        if (pairs[i].getFirst() == key) {
            return;
        }
    }
    if (size == capacity) {
        resize();
    }
    pairs[size].set(key, value);
    size++;
}

template<typename K, typename V>
void Map<K, V>::add(const K &key, V &&value) {
    for (size_t i = 0; i < size; i++) {
        if (pairs[i].getFirst() == key) {
            return;
        }
    }
    if (size == capacity) {
        resize();
    }
    pairs[size].set(key, std::move(value));
    size++;
}

template<typename K, typename V>
bool Map<K, V>::remove(const K &key) {
    for (size_t i = 0; i < size; i++) {
        if (pairs[i].getFirst() == key) {
            pairs[i].set(std::move(pairs[size - 1].getFirst()), std::move(pairs[size - 1].getSecond()));
            size--;
            return true;
        }
    }
    return false;
}

template<typename K, typename V>
bool Map<K, V>::contains(const K &key) const {
    for (size_t i = 0; i < size; i++) {
        if (pairs[i].getFirst() == key) {
            return true;
        }
    }
    return false;
}

template<typename K, typename V>
const V & Map<K, V>::operator[](const K &key) const {
    return pairs[size].getSecond();
}

template<typename K, typename V>
V &Map<K, V>::operator[](const K &key) {
    return pairs[size].getSecond();
}

template<typename K, typename V>
size_t Map<K, V>::getSize() const {
    return size;
}

template<typename K, typename V>
size_t Map<K, V>::getCapacity() const {
    return capacity;
}

template<typename K, typename V>
bool Map<K, V>::empty() const {
    return size == 0;
}

#endif //PAIR_MAP_H
