#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

#include "DynamicArray.h"
#include "LinkedList.h"

void GenerateRandomNumbersFile(int count, std::string& fileName) 
{
    std::ofstream outFile(fileName);
    if (!outFile) {
        std::cerr << "Error opening the file!" << std::endl;
        return;
    }

    std::srand(static_cast<unsigned int>(std::time(0)));

    for (int i = 0; i < count; ++i) {
        int randomNumber = std::rand();
        outFile << randomNumber << std::endl;
    }

    std::cout << "The numbers have been successfully written to the file " << fileName << std::endl;

    outFile.close();
}

Sequence<int>& ReadSequenceFromFile(std::string& fileName, Sequence<int>* numbers)
{
    std::ifstream inFile(fileName);
    if (!inFile) {
        std::cout << "Error opening the file!" << std::endl;
        return *numbers;
    }

    int number;

    while (inFile >> number)
    {
        numbers->Append(number);
    }

    inFile.close();

    return *numbers;
}

void ReadDynamicArrayFromFile(std::string& fileName, DynamicArray<int>* numbers)
{
    numbers = &dynamic_cast<DynamicArray<int>&>(ReadSequenceFromFile(fileName, numbers));
}

void ReadLinkedListFromFile(std::string& fileName, LinkedList<int>* numbers)
{
    numbers = &dynamic_cast<LinkedList<int>&>(ReadSequenceFromFile(fileName, numbers));
}

void WriteSequenceToFile(std::string& fileName, Sequence<int>* numbers)
{
    std::ofstream outFile(fileName);
    if (!outFile) {
        std::cerr << "Error opening the file!" << std::endl;
        return;
    }

    auto begin = numbers->ToBegin();
    auto end = numbers->ToEnd();

    while (*begin != *end)
    {
        outFile << **begin << std::endl;
        ++(*begin);
    }

    std::cout << "The numbers have been successfully written to the file " << fileName << std::endl;

    outFile.close();
}