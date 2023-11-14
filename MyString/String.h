#pragma once
#include <iostream>
class String
{
public:
	String(const char str[]);
	String();
	String(const String& other);
	~String();
	String& operator=(const String other);
	bool operator== (String other);
	String operator+(const char other);

	int findStr(const char searchStr[]);
	int getLength();
	void setLenght(int length);

	void findWordsForDict();

//private:
	int calculateLenghtCharArray(const char str[]);
	int length;
	char* strPointer = nullptr;
	String* dictionary = nullptr;
	int* coutOfWordsInDict = nullptr;
};

