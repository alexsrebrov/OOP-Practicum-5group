#pragma once
#include <iostream>
#include <functional>
#include "Pair.hpp"

template <typename T>
class Vector;

template <typename K, typename V>
class Map;

template <typename T>
class Stream 
{
private:
    T* data;
    size_t size;
    
public:
    Stream(T* data, size_t size);

    /*
    * бихте могли да напишете и
    Stream& filter(bool (*predicate)(const T&));
	но така сте по-лимитирани, тъй като на std::function можете да подавате повече неща
    */
    Stream& filter(std::function<bool(const T&)> predicate);
    Stream& sort(std::function<bool(const T&, const T&)> comparator);
    Stream& limit(int n);

    template <typename K>
    Stream<K> map(std::function<K(const T&)> mapper);

    Vector<T> toVector();
    
    template <typename V>
    Map<T, V> toMap(std::function<V(const T&)> mapper);
};

template<typename T>
Stream<T>::Stream(T* data, size_t size) : size(size) {
    this->data = new T[size];

    for (size_t i = 0; i < size; i++) {
        this->data[i] = data[i];
    }
}

/*ВАЖНО: това което трябва да извлечете от примера е как работят std::function и ламбда функциите. ю
Възможно е да не сме хванали/не сме обходили достатъчно строго някакви edge-cases когато имаме nullptr*/
template<typename T>
Stream<T>& Stream<T>::filter(std::function<bool(const T&)> predicate)
{
    if (!data) 
    {
        return *this;
    }

    size_t count = 0;
    for (size_t i = 0; i < size; i++) {
        if (predicate(data[i])) {
            count++;
        }
    }

    if (!count) 
    {
        delete[] data;
        data = nullptr;

        size = 0;

        return *this;
    }

    T* newData = new T[count];

    count = 0;
    for (size_t i = 0; i < size; i++) {
        if (predicate(data[i])) {
            newData[count] = data[i];
            count++;
        }
    }

    delete[] this->data;
    this->data = newData;
    this->size = count;
    return *this;
}

template<typename T>
Stream<T>& Stream<T>::sort(std::function<bool(const T&, const T&)> comparator) {
    const size_t n = size;

    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;

        for (int j = i + 1; j < n; j++) {
            if (comparator(data[minIdx], data[j])) {
                minIdx = j;
            }
        }

        if (minIdx != i) {
            std::swap(data[i], data[minIdx]);
        }
    }

    return *this;
}

template<typename T>
Stream<T>& Stream<T>::limit(int n) {
    T* newData = new T[n];

    for (size_t i = 0; i < n; i++) {
        newData[i] = data[i];
    }

    delete[] data;
    data = newData;
    this->size = n;
    return *this;
}

template<typename T>
Vector<T> Stream<T>::toVector() {
    Vector<T> result(size, data);
    data = nullptr;

    return result;
}

template<typename T>
template<typename K>
Stream<K> Stream<T>::map(std::function<K(const T&)> mapper)
{
    K* newData = new K[size];

    for (size_t i = 0; i < size; i++) 
    {
        newData[i] = mapper(data[i]);
    }

    Stream<K> result(newData, size);
    delete[] newData;

    return result;
}

template<typename T>
template<typename V>
Map<T, V> Stream<T>::toMap(std::function<V(const T&)> mapper)
{
    Pair<T, V>* newData = new Pair<T, V>[size];

    for (size_t i = 0; i < size; i++)
    {
        newData[i] = { data[i], mapper(data[i]) };
    }

    Map<T, V> result(size, newData);
    data = nullptr;

    return result;
}
