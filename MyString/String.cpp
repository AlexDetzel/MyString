#include "String.h"

String::String(const char str[])
{

	this->length = calculateLenghtCharArray(str);
	this->strPointer = new char[this->length + 1];
	for (int i = 0; i < this->length + 1; i++)
	{
		strPointer[i] = str[i];
	}
}

String::String(const char pathToTxtFile[], bool fillFromPath)
{
	this->length = 0;
	std::ifstream fin;
	fin.open(pathToTxtFile);
	if (!fin.is_open())
	{
		std::cout << "Error IN";
	}
	else
	{
		//std::cout << "file opened";
		char ch;
		while (fin.get(ch))
		{
			this->length += 1;
		}
		fin.close();
	}

	this->strPointer = new char[this->length + 1];

	fin.open(pathToTxtFile);
	if (!fin.is_open())
	{
		std::cout << "Error IN";
	}
	else
	{
		//std::cout << "file opened";
		char ch;
		int counter = 0;
		while (fin.get(ch))
		{
			this->strPointer[counter] = ch;
			counter += 1;
		}
		this->strPointer[this->length] = '\0';
		fin.close();
	}

}

String::String()
{

	this->length = 0;
	this->strPointer = 0;
}

String::String(const String& other)
{

	this->length = other.length;
	
	this->strPointer = new char[other.length + 1];

	for (int i = 0; i < this->length + 1; i++)
	{
		this->strPointer[i] = other.strPointer[i];
	}
}

String::~String()
{
	delete[] strPointer;
	
}


String& String::operator=(const String other)
{

	if (this->strPointer != nullptr)
	{
		delete[] this->strPointer;
	}
	this->length = other.length;
	this->strPointer = new char [this->length + 1];
	for (int i = 0; i < this->length + 1; i++)
	{
		this->strPointer[i] = other.strPointer[i];
	}
	return *this;
}

String& String::operator=(const char str[])
{
	if (this->strPointer != nullptr)
	{
		delete[] this->strPointer;
	}
	this->length = calculateLenghtCharArray(str);
	this->strPointer = new char[this->length + 1];
	for (int i = 0; i < this->length + 1; i++)
	{
		strPointer[i] = str[i];
	}
	return *this;
}

bool String::operator==(String other)
{
	if (this->length != other.length)
		return false;
	for (int i = 0; i < other.length; i++)
	{
		if (std::toupper(this->strPointer[i]) != std::toupper(other.strPointer[i]))
			return false;
	}
	return true;
}

String String::operator+(const char other)
{
	String newString;
	newString.setLenght(this->length + 1);
	for (int i = 0; i < this->length + 1; i++)
	{
		newString.strPointer[i] = this->strPointer[i];
	}
	newString.strPointer[this->length + 1] = '\0';
	newString.strPointer[this->length] = other;
	return newString;  //Вышла за поле видимости но почему не уничтожилась деструктором?
}

void String::safeInTxtFile(String txtFileName)
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
		for (int i = 0; i < this->length; i++)
		{
			fout << this->getValueString()[i];
		}
		fout.close();
	}
}

String String::operator+(String other)
{
	String newString;
	newString.setLenght(this->length + other.length);
	newString.strPointer = new char[newString.length + 1];
	for (int i = 0; i < this->length; i++)
	{
		newString.strPointer[i] = this->strPointer[i];
	}
	for (int i = this->length; i < this->length + other.length + 1; i++)
	{
		newString.strPointer[i] = other.strPointer[i - this->length];
	}
	return newString;
}

int String::findStr(const char searchStr[])
{
	int countLetterSame = 0;
	int indexMyString = 0;
    int indexSearch = 0;
	
	while (true)
	{
		if (countLetterSame == calculateLenghtCharArray(searchStr))
			return indexMyString - countLetterSame;
		if (indexMyString == this->length - 1)
			return -1;
		if (this->strPointer[indexMyString] == searchStr[indexSearch])
		{
			countLetterSame += 1;
			indexMyString += 1;
			indexSearch += 1;
		}
		else
		{
			if (indexSearch != 0) {
				indexSearch = 0;
				countLetterSame = 0;
			}
			else
			{
				indexMyString += 1;
				countLetterSame = 0;
			}
		}
	}
	return 1;
}

int String::findStr(const String searchStr)
{
	int countLetterSame = 0;
	int indexMyString = 0;
	int indexSearch = 0;

	while (true)
	{
		if (countLetterSame == calculateLenghtCharArray(searchStr.strPointer))
			return indexMyString - countLetterSame;
		if (indexMyString == this->length - 1)
			return -1;
		if (this->strPointer[indexMyString] == searchStr.strPointer[indexSearch])
		{
			countLetterSame += 1;
			indexMyString += 1;
			indexSearch += 1;
		}
		else
		{
			if (indexSearch != 0) {
				indexSearch = 0;
				countLetterSame = 0;
			}
			else
			{
				indexMyString += 1;
				countLetterSame = 0;
			}
		}
	}
	return 1;
}

int String::getLength()
{
	return this->length;
}

void String::setLenght(int length)
{
	this->length = length;
	delete [] this->strPointer;
	this->strPointer = new char[this->length + 1];
}

void String::setValueString(const char str[])
{   
	this->length = calculateLenghtCharArray(str);
	delete[] this->strPointer;
	this->strPointer = new char[this->length + 1];
	for (int i = 0; i < this->length + 1; i++)
	{
		strPointer[i] = str[i];
	}
}

char* String::getValueString()
{
	return this->strPointer;
}


int String::calculateCountOfWordsInString()
{
	int count = 0;
	bool wasWord = false;
	bool isWordNow;
	for (int i = 0; i < this->length + 1; i++)
	{
		isWordNow = (this->strPointer[i] == '-' || strPointer[i] >= 'a' && strPointer[i] <= 'z' || strPointer[i] >= 'A' && strPointer[i] <= 'Z');


		if (wasWord && !isWordNow)
		{
			count += 1;
		}

		if (isWordNow)
		{
			wasWord = true;
		}
		else wasWord = false;

	}
	return count;
}

int String::calculateLenghtCharArray(const char str[])
{
	int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return i;
}
