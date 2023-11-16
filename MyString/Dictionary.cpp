#include "Dictionary.h"



void Dictionary::fillDict(String string)
{
	String word("");
	this->vectorOfCouple.clear();
	for (int i = 0; i < string.getLength() + 1; i++)
	{
		if (string.getValueString()[i] == '-' || string.getValueString()[i] >= 'a' && string.getValueString()[i] <= 'z' || string.getValueString()[i] >= 'A' && string.getValueString()[i] <= 'Z')
		{
			if (word.getLength() == 0)
			{
				word = word + std::toupper(string.getValueString()[i]);
			}
			else 
				word = word + string.getValueString()[i];
		}
		else
		{
			if (word.getValueString()[0] != '\0' && word.getValueString()[0] != '-')
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
	std::cout << "List of Words in dictionary:\n";
	for (int i = 0; i < this->vectorOfCouple.size(); i++)
	{
		std::cout << vectorOfCouple[i].first.getValueString() << " - " << vectorOfCouple[i].second << '\n';
	}
}

void Dictionary::sordDictByAlphabet()
{
	for (int i = 0; i < this->vectorOfCouple.size(); i++)
	{
		for (int j = i; j < this->vectorOfCouple.size(); j++)
		{
			if (this->vectorOfCouple[i].first.getValueString()[0] > this->vectorOfCouple[j].first.getValueString()[0])
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

void Dictionary::safeDictInCsv(String txtFileName)
{
	std::ofstream fout;
	fout.open(txtFileName.getValueString());
	if (!fout.is_open())
	{
		std::cout << "error in fout";
	}
	else
	{
		//std::cout << "all good in fout";
		for (int i = 0; i < this->vectorOfCouple.size(); i++)
		{
			fout << this->vectorOfCouple[i].first.getValueString() << ',' << vectorOfCouple[i].second << '\n';
		}
		fout.close();
	}
}
