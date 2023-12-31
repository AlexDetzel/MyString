#pragma once
#include <iostream>
#include "String.h"
#include "vector"
#include <fstream>
class Dictionary
{
public:
	void fillDict(String string);
	bool isWordInDict(String str);
	int findWordInDict(String str);
	void printDict();
	void sordDictByAlphabet();
	void sordDictByFrequency();
	void safeDictInCsv(String txtFileName);
private:
	std::vector<std::pair<String, int>> vectorOfCouple;
};

