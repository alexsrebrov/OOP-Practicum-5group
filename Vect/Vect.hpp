#ifndef VECT_VECT_H
#define VECT_VECT_H

#include <iostream>

template <typename T> class Vector {
    size_t size;
    size_t capacity;
    T* data;
    void free();
    void copyFrom(const Vector<T>& other);
    void moveFrom(Vector<T>&& other);
    void resize();
    void shiftFront(int start);
    void shiftBack(int start);
public:
    Vector();
    explicit Vector(size_t n);
    Vector(size_t n, const T& obj);
    Vector(const Vector<T>& other);
    Vector(Vector<T>&& other) noexcept;
    Vector<T>& operator=(const Vector<T>& other);
    Vector<T>& operator=(Vector<T>&& other) noexcept;
    ~Vector();
    size_t getSize() const;
    size_t getCapacity() const;
    void push_back(const T& obj);
    void push_back(T&& obj);
    void pop_back();
    void insert(size_t idx, const T& obj);
    void insert(size_t idx, T&& obj);
    void erase(size_t idx);
    const T* begin() const;
    T* begin();
    const T* end() const;
    T* end();
    const T& operator[](size_t idx) const;
    T& operator[](size_t idx);
    void shrink_to_fit();
    bool empty() const;
    void clear();
};

template<typename T>
Vector<T>::Vector() : size(0), capacity(8) {
    data = new T[capacity];
}

template<typename T>
Vector<T>::Vector(size_t n) : size(0), capacity(n) {
    data = new T[n];
}

template<typename T>
Vector<T>::Vector(size_t n, const T &obj) : size(n), capacity(n) {
    data = new T[n];
    for (size_t i = 0; i < n; i++) {
        data[i] = obj;
    }
}

template<typename T>
Vector<T>::Vector(const Vector<T>& other) {
    copyFrom(other);
}

template<typename T>
Vector<T>::Vector(Vector<T>&& other) noexcept {
    moveFrom(std::move(other));
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

template<typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& other) noexcept {
    if (this != &other) {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

template<typename T>
Vector<T>::~Vector() {
    free();
}

template<typename T>
size_t Vector<T>::getSize() const {
    return size;
}

template<typename T>
size_t Vector<T>::getCapacity() const {
    return capacity;
}

template<typename T>
void Vector<T>::push_back(const T& obj) {
    if (size == capacity) {
        resize();
    }
    this -> data[size++] = obj;
}

template<typename T>
void Vector<T>::push_back(T&& obj) {
    if (size == capacity) {
        resize();
    }
    this -> data[size++] = std::move(obj);
}

template<typename T>
void Vector<T>::pop_back() {
    if (size == 0) {
        return;
    }
    size--;
}

template<typename T>
void Vector<T>::insert(size_t idx, const T& obj) {
    if (size == capacity) {
        resize();
    }
    shiftFront(idx);
    this -> data[idx] = obj;
    size++;
}

template<typename T>
void Vector<T>::insert(size_t idx, T&& obj) {
    if (size == capacity) {
        resize();
    }
    shiftFront(idx);
    this -> data[idx] = std::move(obj);
    size++;
}

template<typename T>
void Vector<T>::erase(size_t idx) {
    shiftBack(idx);
    size--;
}

template<typename T>
const T* Vector<T>::begin() const {
    return data;
}

template<typename T>
T* Vector<T>::begin() {
    return data;
}

template<typename T>
const T* Vector<T>::end() const {
    return data + size;
}

template<typename T>
T* Vector<T>::end() {
    return data + size;
}

template<typename T>
const T& Vector<T>::operator[](size_t idx) const {
    return data[idx];
}

template<typename T>
T& Vector<T>::operator[](size_t idx) {
    return data[idx];
}

template<typename T>
void Vector<T>::shrink_to_fit() {
    T* newArray = new T[size];
    for (int i = 0; i < size; i++) {
        newArray[i] = std::move(data[i]);
    }
    delete[] data;
    data = newArray;
    capacity = size;
}

template<typename T>
bool Vector<T>::empty() const {
    return size == 0;
}

template<typename T>
void Vector<T>::clear() {
    size = 0;
}

template<typename T>
void Vector<T>::free() {
    delete[] data;
}

template<typename T>
void Vector<T>::copyFrom(const Vector<T>& other) {
    data = new T[other.capacity];
    for (int i = 0; i < other.size; i++) {
        data[i] = other.data[i];
    }
    this -> capacity = other.capacity;
    this -> size = other.size;
}

template<typename T>
void Vector<T>::moveFrom(Vector<T>&& other) {
    this -> data = other.data;
    other.data = nullptr;
    this -> capacity = other.capacity;
    this -> size = other.size;
}

template<typename T>
void Vector<T>::resize() {
    if (size > 0) {
        T* newVector = new T[capacity * 2];
        for (int i = 0; i < size; i++) {
            newVector[i] = std::move(data[i]);
        }
        delete[] data;
        data = newVector;
        capacity *= 2;
    }
    else {
        data = new T[1];
        capacity = 1;
    }
}

template<typename T>
void Vector<T>::shiftFront(int start) {
    for (int i = size; i > start; i--) {
        data[i] = std::move(data[i - 1]);
    }
}

template<typename T>
void Vector<T>::shiftBack(int start) {
    for (int i = start; i + 1 < size; i++) {
        data[i] = std::move(data[i + 1]);
    }
}
#endif //VECT_VECT_H
