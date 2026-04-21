#include "String.h"

void String::resize() {
    if (capacity) {
        auto newArray = new char[capacity * 2];
        strcpy(newArray, str);
        free();
        str = newArray;
        capacity = capacity * 2;
    }
    else {
        capacity = 1;
        auto newArray = new char[capacity];
        strcpy(newArray, str);
    }
}

void String::copyFrom(const String& other) {
    this -> str = new char[other.length() + 1];
    strcpy(this -> str, other.str);
    this -> size = other.size;
    this -> capacity = other.capacity;
}

void String::moveFrom(String&& other) {
    this -> str = other.str;
    other.str = nullptr;
    this -> size = other.size;
    this -> capacity = other.capacity;
}

void String::free() {
    delete[] str;
}

String::String() = default;

String::String(const char* str) {
    this -> str = new char[strlen(str) + 1];
    strcpy(this -> str, str);
}

String::String(const String& other) {
    copyFrom(other);
}

String::String(String&& other) {
    moveFrom(std::move(other));
}

String::~String() {
    free();
}

String & String::operator=(const String& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

String & String::operator=(String&& other) {
    if (this != &other) {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

size_t String::length() const {
    if (this -> str) {
        return strlen(this -> str);
    }
    return 0;
}

char & String::operator[](size_t index) {
    return str[index];
}

const char & String::operator[](size_t index) const {
    return str[index];
}

String & String::operator+=(const String &other) {
    size_t l1 = this -> length(), l2 = other.length();
    while (capacity < l1 + l2 + 1) {
        resize();
    }
    strcat(this -> str, other.str);
    return *this;
}

bool String::operator==(const String &other) const {
    size_t l1 = this -> length(), l2 = other.length();
    if (l1 != l2) {
        return false;
    }
    for (size_t index = 0; index < l1; index++) {
        if (this -> str[index] != other[index]) {
            return false;
        }
    }
    return true;
}

bool String::operator!=(const String &other) const {
    return !(*this == other);
}