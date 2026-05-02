#ifndef STACK_STACK_H
#define STACK_STACK_H
#include <iostream>

template <typename T> class Stack {
    T* array;
    size_t size;
    size_t capacity;
    void resize();
public:
    Stack<T>();
    ~Stack<T>();
    void push(const T& element);
    void push(T&& element);
    void pop();
    T& top() const;
    bool empty() const;
    size_t getSize() const;
};

template<typename T>
void Stack<T>::resize() {
    if (size > 0) {
        T* newArray = new T[capacity * 2];
        for (size_t i = 0; i < size; i++) {
            newArray[i] = array[i];
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
Stack<T>::Stack() : array(nullptr), size(0), capacity(0) {}

template<typename T>
Stack<T>::~Stack() {
    delete[] array;
}

template<typename T>
void Stack<T>::push(const T &element) {
    if (size == capacity) {
        resize();
    }
    array[size++] = element;
}

template<typename T>
void Stack<T>::push(T &&element) {
    if (size == capacity) {
        resize();
    }
    array[size++] = std::move(element);
}

template<typename T>
void Stack<T>::pop() {
    size--;
}

template<typename T>
T & Stack<T>::top() const {
    return array[size - 1];
}

template<typename T>
bool Stack<T>::empty() const {
    return size == 0;
}

template<typename T>
size_t Stack<T>::getSize() const {
    return size;
}
#endif //STACK_STACK_H
