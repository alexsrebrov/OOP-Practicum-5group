#pragma once

int myStrLen(const char* str);
void myStrCopy(char* destination, const char* source);
void myStrCat(char* str1, const char* str2);
int myStrCmp(const char* str1, const char* str2);
bool containsChar(const char* str, char ch);
bool isPrefix(const char* str1, const char* str2);
bool containsStr(const char* str1, const char* str2);
void toLower(char* str);
void toUpper(char* str);
char toLower(char ch);
char toUpper(char ch);
bool isLower(char ch);
bool isUpper(char ch);
int toFindChar(const char* str, char ch);
int toFindstr(const char* str1, const char* str2);