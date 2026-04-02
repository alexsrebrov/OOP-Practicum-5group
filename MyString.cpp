#include "MyString.h"
#include <iostream>

void MyString::free()
{
    delete[] str;
    str = nullptr;
}

void MyString::copyFrom(const MyString& other)
{
    setName(other.str);
}

void MyString::moveFrom(MyString&& other)
{
    str = other.str;
    other.str = nullptr;
}

MyString::MyString():str(nullptr){}

MyString::MyString(const char* str):str(nullptr)
{
    setName(str);
}

MyString::MyString(const MyString& other) : str(nullptr)
{
    copyFrom(other);
}

MyString::MyString(MyString&& other)
{
    moveFrom(std::move(other));
}

MyString& MyString::operator=(const MyString& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

MyString& MyString::operator=(MyString&& other)noexcept
{
    if (this != &other)
    {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

MyString::~MyString()
{
    free();
}

MyString& MyString::operator+=(const MyString& other)
{
    if (!other.str)return *this;
    size_t newLen = ~*this + ~other;
    char* temp = new char[newLen + 1];
    myStrCopy(temp, str);
    myStrCat(temp, other.str);
    free();
    str = temp;
    return *this;
}

bool MyString::operator==(const MyString& other)const
{
    return myStrCmp(str, other.str) == 0;
}

bool MyString::operator!=(const MyString& other) const
{
    return !(*this == other);
}

bool MyString::operator<(const MyString& other) const
{
    return myStrCmp(str, other.str) < 0;
}

bool MyString::operator>(const MyString& other) const
{
    return (!(*this < other) && !(*this == other));
}

bool MyString::operator>=(const MyString& other) const
{
    return !(*this < other);
}

bool MyString::operator<=(const MyString& other) const
{
    return !(*this > other);
}

const char& MyString::operator[](int index) const
{
    return str[index];
}

char& MyString::operator[](int index)
{
    return str[index];
}

int MyString::operator~() const
{
    return myStrLen(str);
}

bool MyString::operator!() const
{
    return ~*this == 0;
}

MyString MyString::operator+(const MyString& other)
{
    MyString result(*this);
    result += other;
    return result;
}

MyString& MyString::insert(size_t index, char ch)
{
    size_t size = ~*this;
    if (index > size)index = size;
    char* temp=new char[size+2];
    for (size_t i = 0; i < index; ++i)
    {
        temp[i] = str[i];
    }
    temp[index] = ch;
    for (int i = index; i < ~*this; ++i)
    {
        temp[i+1] = str[i];
    }
    temp[size+1] = '\0';
    free();
    str = temp;
    return *this;
}

MyString& MyString::insert(size_t index, const char* str)
{
    if (!str)return*this;
    size_t size = ~*this;
    if (index > size)index = size;
    size_t sizeStr = myStrLen(str);
    size_t newSize = size + sizeStr;
    char* temp = new char[newSize+1];
    for (size_t i = 0; i < index; ++i)
    {
        temp[i] = this->str[i];
    }
    for (size_t i = 0; i < sizeStr; ++i) {
        temp[index + i] = str[i];
    }
    for (size_t i = index; i < ~*this; ++i)
    {
        temp[i + sizeStr] = this->str[i];
    }
    temp[newSize] = '\0';
    free();
    this->str = temp;
    return *this;
}

void MyString::setName(const char* str)
{
    free();
    if (!str)
    {
        this->str = nullptr;
        return;
    }
    this->str = new char[myStrLen(str) + 1];
    myStrCopy(this->str, str);

}

MyString& MyString::insert(size_t index, const MyString& str)
{
    if (!str.str)return*this;
    size_t size = ~*this;
    if (index > size)index = size;
    insert(index, str.str);
    return *this;
}

MyString& MyString::erase(size_t index)
{
    size_t size = ~*this;
    if (index > size)return *this;
    char* temp = new char[size];
    size_t newIndex = 0;
    for (size_t i = 0; i < size; ++i)
    {
        if (i == index)continue;
        temp[newIndex++] = str[i];
    }
    temp[newIndex] = '\0';
    free();
    str = temp;
    return*this;
}

MyString& MyString::erase(size_t index, size_t count)
{
    size_t size = ~*this;
    if (index+count > size)return *this;
    char* temp = new char[size-count+1];
    size_t newIndex = 0;
    for (size_t i = 0; i < size; ++i)
    {
        if (i >= index&&i<index+count)continue;
        temp[newIndex++] = str[i];
    }
    temp[newIndex] = '\0';
    free();
    str = temp;
    return*this;
}

bool MyString::contains(char ch)const
{
    return containsChar(str, ch);
}

bool MyString::contains(const char* str) const
{
    return containsStr(this->str, str);
}

bool MyString::contains(const MyString& str) const
{
    return contains(str.str);
}

MyString MyString::substr(size_t pos, size_t len) const
{
    size_t size = ~*this;
    if (pos > size)return MyString();
    if (pos + len > size)len = size - pos;
    char* temp = new char[len+1];
    size_t index = 0;
    for (size_t i = pos; i < pos + len; ++i)
    {
        temp[index++] = str[i];
    }
    temp[index] = '\0';
    MyString result(temp);
    delete[] temp;
    return result;
}

void MyString::toLower()
{
    ::toLower(str);
}

void MyString::toUpper()
{
    ::toUpper(str);
}

int MyString::find(char ch)
{
    return toFindChar(str, ch);
}

int MyString::find(const char* str)
{
    return toFindstr(this->str, str);
}

MyString& MyString::replace(const char* str1, const char* newStr)
{
    int index = find(str1);
    int len = myStrLen(str1);
    if (index != -1)
    {
        erase(index, len);
        insert(index, newStr);
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const MyString& other)
{
    if (other.str)
    {
        os << other.str;
    }
    return os;
}

std::istream& operator>>(std::istream& is, MyString& other)
{
    char buffer[1024];
    is >> buffer;
    other.setName(buffer);
    return is;
}
