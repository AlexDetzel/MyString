#pragma once
#include <iostream>
#include <fstream>
class String
{
public:
	String(const char str[]);
	String(const char pathToTxtFile[], bool fillFromPath);
	String();
	String(const String& other);
	~String();
	String& operator=(const String other);
	String& operator=(const char str[]);

	bool operator== (String other);

	String operator+(String other);
	String operator+(const char other);
	
	void safeInTxtFile(String txtFileName);

	int findStr(const String searchStr);
	int findStr(const char searchStr[]);
	
	int getLength();
	void setLenght(int length);

	void setValueString(const char str[]);
	char* getValueString();

	int calculateCountOfWordsInString();

private:

	int calculateLenghtCharArray(const char str[]);
	int length;
	char* strPointer = nullptr;
};

