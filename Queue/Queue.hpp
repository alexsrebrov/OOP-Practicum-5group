#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H
#include <iostream>

template <typename T> class Queue {
    T* array;
    size_t size;
    size_t capacity;
    void resize();
public:
    Queue<T>();
    void push(const T& element);
    void push(T&& element);
    void pop();
    T& front() const;
    T& back() const;
    bool empty() const;
    size_t getSize() const;
};

template<typename T>
void Queue<T>::resize() {
    if (size > 0) {
        T* newArray = new T[capacity * 2];
        for (size_t i = 0; i < size; i++) {
            newArray[i] = std::move(array[i]);
        }
        delete[] array;
        array = newArray;
        capacity *= 2;
    }
    else {
        array = new T[1];
        capacity = 1;
    }
}

template<typename T>
Queue<T>::Queue() : array(nullptr), size(0), capacity(0) {}

template<typename T>
void Queue<T>::push(const T &element) {
    if (size == capacity) {
        resize();
    }
    array[size++] = element;
}

template<typename T>
void Queue<T>::push(T &&element) {
    if (size == capacity) {
        resize();
    }
    array[size++] = std::move(element);
}

template<typename T>
void Queue<T>::pop() {
    if (size > 0) {
        size--;
    }
}

template<typename T>
T & Queue<T>::front() const {
    return array[size - 1];
}

template<typename T>
T & Queue<T>::back() const {
    return array[0];
}

template<typename T>
bool Queue<T>::empty() const {
    return size == 0;
}

template<typename T>
size_t Queue<T>::getSize() const {
    return size;
}
#endif //QUEUE_QUEUE_H
