#include "Dictionary.h"



void Dictionary::fillDict(String string)
{
	String word("");
	this->vectorOfCouple.clear();
	for (int i = 0; i < string.length + 1; i++)
	{
		if (string.strPointer[i] == '-' || string.strPointer[i] >= 'a' && string.strPointer[i] <= 'z' || string.strPointer[i] >= 'A' && string.strPointer[i] <= 'Z')
		{
			if (word.length == 0)
			{
				word = word + std::toupper(string.strPointer[i]);
			}
			else 
				word = word + string.strPointer[i];
		}
		else
		{
			if (word.strPointer[0] != '\0' && word.strPointer[0] != '-')
			{
				if (!(this->isWordInDict(word)))
				{
					std::pair<String, int> newWord = { word, 1 };
					this->vectorOfCouple.push_back(newWord);
				}
				else 
				{
					int countNow = vectorOfCouple[this->findWordInDict(word)].second;
					std::pair<String, int> newWord = { word, countNow + 1 };
					this->vectorOfCouple[this->findWordInDict(word)] = newWord;
				}
				
			}
			word.setValueString("");
		}

	}
}

bool Dictionary::isWordInDict(String str)
{
	for (int i = 0; i < this->vectorOfCouple.size(); i++)
	{
		if (vectorOfCouple[i].first == str)
			return true;
	}
	return false;
}

int Dictionary::findWordInDict(String str)
{
	for (int i = 0; i < this->vectorOfCouple.size(); i++)
	{
		if (vectorOfCouple[i].first == str)
			return i;
	}
	return -1;
}

void Dictionary::printDict()
{
	std::cout << "List of Words in dictionary\n\n";
	for (int i = 0; i < this->vectorOfCouple.size(); i++)
	{
		std::cout << vectorOfCouple[i].first.strPointer << " - " << vectorOfCouple[i].second << '\n';
	}
}

void Dictionary::sordDictByAlphabet()
{
	for (int i = 0; i < this->vectorOfCouple.size(); i++)
	{
		for (int j = i; j < this->vectorOfCouple.size(); j++)
		{
			if (this->vectorOfCouple[i].first.strPointer[0] > this->vectorOfCouple[j].first.strPointer[0])
				swap(vectorOfCouple[i], vectorOfCouple[j]);
		}
		
	}
}

void Dictionary::sordDictByFrequency()
{
	for (int i = 0; i < this->vectorOfCouple.size(); i++)
	{
		for (int j = i; j < this->vectorOfCouple.size(); j++)
		{
			if (this->vectorOfCouple[i].second < this->vectorOfCouple[j].second)
				swap(vectorOfCouple[i], vectorOfCouple[j]);
		}

	}
}
