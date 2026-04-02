#pragma once
#include "myStrFunctions.h"
#include <iostream>
class MyString
{
private:
	char* str;

	void free();
	void copyFrom(const MyString& other);
	void moveFrom(MyString&& other);
public:
	MyString();
	MyString(const char* str);
	MyString(const MyString& other);
	MyString(MyString&& other);
	MyString& operator=(const MyString& other);
	MyString& operator=(MyString&& other);
	~MyString();
	MyString& operator+=(const MyString& other);
	bool operator==(const MyString& other)const;
	bool operator!=(const MyString& other)const;
	bool operator<(const MyString& other)const;
	bool operator>(const MyString& other)const;
	bool operator>=(const MyString& other)const;
	bool operator<=(const MyString& other)const;
	const char& operator[](int index) const;
	char& operator[](int index);
	int operator~()const;
	bool operator!()const;
	friend std::ostream& operator<<(std::ostream& os, const MyString& other);
	friend std::istream& operator>>(std::istream& is, const MyString& other);
	MyString operator+(const MyString& other);
	MyString& insert(size_t index, char ch);
	MyString& insert(size_t index, const char* str);
	void setName(const char* str);
	MyString& insert(size_t index, const MyString& str);
	MyString& erase(size_t index);
	MyString& erase(size_t index, size_t count);
	bool contains(char ch)const;
	bool contains(const char* str)const;
	bool contains(const MyString& str)const;
	MyString substr(size_t pos, size_t len) const;
	void toLower();
	void toUpper();
	int find(char ch);
	int find(const char* str);
	MyString& replace(const char* str1, const char* newStr);
};