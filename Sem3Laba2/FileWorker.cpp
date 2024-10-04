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

void ReadDynamicArrayFromFile(std::string& fileName, DynamicArray<int>* numbers)
{
    std::ifstream inFile(fileName);
    if (!inFile) {
        std::cout << "Error opening the file!" << std::endl;
        return;
    }

    int number;

    while (inFile >> number)
    {
        numbers->Append(number);
    }

    inFile.close();
}

void ReadLinkedListFromFile(std::string& fileName, LinkedList<int>* numbers)
{
    std::ifstream inFile(fileName);
    if (!inFile) {
        std::cout << "Error opening the file!" << std::endl;
        return;
    }

    int number;

    while (inFile >> number)
    {
        numbers->Append(number);
    }

    inFile.close();
}

void WriteDynamicArrayToFile(std::string& fileName, DynamicArray<int>* numbers)
{
    std::ofstream outFile(fileName);
    if (!outFile) {
        std::cerr << "Error opening the file!" << std::endl;
        return;
    }

    for (int i = 0; i < numbers->GetLength(); ++i) {
        outFile << numbers->GetElement(i) << std::endl;
    }

    std::cout << "The numbers have been successfully written to the file " << fileName << std::endl;

    outFile.close();
}

void WriteLinkedListToFile(std::string& fileName, LinkedList<int>* numbers)
{
    std::ofstream outFile(fileName);
    if (!outFile) {
        std::cerr << "Error opening the file!" << std::endl;
        return;
    }

    for (int i = 0; i < numbers->GetLength(); ++i) {
        outFile << numbers->GetElement(i) << std::endl;
    }

    std::cout << "The numbers have been successfully written to the file " << fileName << std::endl;

    outFile.close();
}