#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H
#include <iostream>



class Vector {
    int* array = nullptr;
    size_t size = 0;
    size_t capacity = 0;
    void free();
    void copyFrom(const Vector &other);
    void moveFrom(Vector &&other);
    void resize();
public:
    Vector();
    ~Vector();
    Vector(const Vector&);
    Vector& operator=(const Vector&);
    Vector(Vector&&);
    Vector& operator=(Vector&&);

    void push_back(int);
    void pop_back();
    void clear();
    bool isEmpty() const;
    size_t getSize() const;
    size_t getCapacity() const;
    int& operator[](int index);
    const int& operator[](int index) const;
};



#endif //VECTOR_VECTOR_H
