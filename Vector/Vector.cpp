#include "Vector.h"

#include <algorithm>
using namespace std;

void Vector::free() {
    delete[] this -> array;
}

void Vector::copyFrom(const Vector& other) {
    array = new int[other.capacity];
    for (int i = 0; i < other.capacity; i++) {
        this -> array[i] = other.array[i];
    }
    this -> size = other.size;
    this -> capacity = other.capacity;
}

void Vector::moveFrom(Vector&& other) {
    this -> array = other.array;
    this -> size = other.size;
    this -> capacity = other.capacity;
    other.array = nullptr;
}

void Vector::resize() {
    if (capacity) {
        const auto newArray = new int[capacity * 2];
        for (int i = 0; i < size; i++) {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
        capacity *= 2;
    }
    else {
        capacity = 1;
        const auto newArray = new int[capacity];
        delete[] array;
        array = newArray;
    }
}

Vector::Vector() : array(new int[capacity]) {}
Vector::~Vector() {
    free();
}

Vector::Vector(const Vector& other) {
    copyFrom(other);
}

Vector& Vector::operator=(const Vector& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

Vector::Vector(Vector&& other) {
    moveFrom(std::move(other));
}

Vector& Vector::operator=(Vector&& other) {
    if (this != &other) {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

void Vector::push_back(int n) {
    while (size >= capacity) {
        resize();
    }
    array[size++] = n;
}

void Vector::pop_back() {
    if (size) {
        array[--size] = 0;
    }
}

void Vector::clear() {
    for (int i = 0; i < size; i++) {
        array[i] = 0;
    }
    this -> size = 0;
}

bool Vector::isEmpty() const {
    return size == 0;
}

size_t Vector::getSize() const {
    return size;
}

size_t Vector::getCapacity() const {
    return capacity;
}

int& Vector::operator[](int index) {
    return array[index];
}

const int& Vector::operator[](int index) const {
    return array[index];
}
