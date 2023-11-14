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
	void setValueString(const char str[]);

	
	void printDict();
	

	int calculateCountOfWordsInString();

//private:
	void findWordsForDict();
	void addWordToDict(String word);
	bool isWordInDict(String word);
	int calculateLenghtCharArray(const char str[]);
	int length;
	char* strPointer = nullptr;

	String* dictionary = nullptr;
	int sizeOfDictionary = 0;
	int* arrayWithcoutUniWordsInDict = nullptr;
};

