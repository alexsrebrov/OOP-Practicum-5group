#ifndef STRING_STRING_H
#define STRING_STRING_H
#include <iostream>


class String {
    char* str = nullptr;
    size_t size = 0;
    size_t capacity = 0;
    void resize();
    void copyFrom(const String&);
    void moveFrom(String &&other);
    void free();
public:
    String();
    explicit String(const char*);
    String(const String&);
    String(String&&);
    ~String();
    String& operator=(const String&);
    String& operator=(String&&);
    size_t length() const;
    char& operator[](size_t index);
    const char& operator[](size_t index) const;
    String& operator+=(const String& other);
    bool operator==(const String& other) const;
    bool operator!=(const String& other) const;
};



#endif //STRING_STRING_H
