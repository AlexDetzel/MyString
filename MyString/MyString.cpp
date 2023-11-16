// MyString.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "String.h"
#include "Dictionary.h"

int main()
{
    String a("asdf Ddf csdcsdfs Ddf bfsdfds dasdasdas Ddf c Ddf");
    String b("sdas asdads fdfs ");
    String c = a + b;
    Dictionary myDictionary;
    myDictionary.fillDict(c);
    myDictionary.sordDictByAlphabet();
    myDictionary.sordDictByFrequency();
    myDictionary.printDict();
    myDictionary.safeDictInCsv(String("myDictionary.txt"));
    std::cout << c.getValueString();

    String d("MyString.txt", 1);
    std::cout << d.getValueString();

    a.safeInTxtFile(String("abc"));


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
