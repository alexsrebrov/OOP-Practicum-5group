#include <iostream>
#include "myStrFunctions.h"

int myStrLen(const char* str)
{
	if (!str)return;
	int len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return len;
}

void myStrCopy(char* destination, const char* source)
{
	if (!source)return;
	while (*source)
	{
		*destination = *source;
		destination++;
		source++;
	}
	destination = '\0';
}

void myStrCat(char* str1, const char* str2)
{
	if (!str2 || !str1)return;
	int str1Len = myStrLen(str1);
	str1 += str1Len;
	myStrCopy(str1, str2);
}

int myStrCmp(const char* str1, const char* str2)
{
	if (!str1 || !str2)return;
	while (*str1 == *str2 && *str1 && *str2)
	{
		str1++;
		str2++;
	}
	return *str1 - *str2;
}

bool containsChar(const char* str, char ch)
{
	if (!str)return false;
	while (*str)
	{
		if (*str == ch)
			return true;
		str++;
	}
	return false;
}

bool isPrefix(const char* str1, const char* str2)
{
	if (!str1)return false;
	while (*str1&&*str2)
	{
		if (*str1 != *str2)
			return false;
		str1++;
		str2++;
	}
	return *str2 == '\0';
}

bool containsStr(const char* str1, const char* str2)
{
	if (!str1) return false;
	size_t size1 = myStrLen(str1);
	size_t size2 = myStrLen(str2);
	if (size2 > size1) return false;
	for (size_t i = 0; i <= size1 - size2; ++i)
	{
		if (isPrefix(str1, str2))
		{
			return true;
		}
		str1++;
	}
	return false;
}

void toLower(char* str)
{
	if (!str)return;
	while (*str)
	{
		if(isUpper(*str))
		{
			*str = toLower(*str);
		}
		str++;
	}
}

void toUpper(char* str)
{
	if (!str)return;
	while (*str)
	{
		if(isLower(*str))
		{
			*str = toUpper(*str);
		}
		str++;
	}
}

char toLower(char ch)
{
	return ch + 'a' - 'A';
}

char toUpper(char ch)
{
	return ch - 'a' + 'A';
}

bool isLower(char ch)
{
	return ch >= 'a' && ch <= 'z';
}

bool isUpper(char ch)
{
	return ch >= 'A' && ch <= 'z';
}

int toFindChar(const char* str, char ch)
{
	if (!str)return -1;
	int index=0;
	while (*str)
	{
		if (*str == ch)
			return index;
		index++;
		str++;
	}
	return -1;
}

int toFindstr(const char* str1, const char* str2)
{
	if (!str1) return -1;
	size_t size1 = myStrLen(str1);
	size_t size2 = myStrLen(str2);
	if (size2 == 0) return 0;
	int index = 0;
	if (size2 > size1) return -1;
	for (size_t i = 0; i <= size1 - size2; ++i)
	{
		if (isPrefix(str1, str2))
		{
			return index;
		}
		index++;
		str1++;
	}
	return -1;
}

