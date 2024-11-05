#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <sstream>

#include "DynamicArray.h"
#include "People.h"

void GenerateRandomFile(int count, std::string& fileName)
{
    std::ofstream file(fileName);
    if (!file) {
        std::cerr << "Error opening the file!" << std::endl;
        return;
    }

    for (int i = 0; i < count; ++i) {
        People people = People();

        file << people.GetLastName() << " "
            << people.GetFirstName() << " "
            << people.GetPatronymic() << " "
            << people.GetBirthDate() << " "
            << people.GetAccountBalance() << "\n";
    }

    std::cout << "The data have been successfully written to the file " << fileName << std::endl;

    file.close();
}

Sequence<People>& ReadSequenceFromFile(std::string& fileName, Sequence<People>* sequence)
{
    std::ifstream file(fileName);
    if (!file) {
        std::cout << "Error opening the file!" << std::endl;
        return *sequence;
    }

    int numLines = std::count(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>(), '\n');
    file.seekg(0, std::ios::beg);

    int i = 0;
    People* array = new People[numLines];
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string firstName, lastName, patronymic, birthDate;
        int accountBalance;

        if (!(iss >> lastName >> firstName >> patronymic >> birthDate >> accountBalance)) {
            std::cerr << "Error reading line: " << line << std::endl;
            continue;
        }

        People person(firstName, lastName, patronymic, birthDate, accountBalance);
        array[i] = person;
        i++;
    }

    file.close();

    sequence->Append(array, numLines);

    delete[] array;

    return *sequence;
}

void ReadDynamicArrayFromFile(std::string& fileName, DynamicArray<People>* sequence)
{
    sequence = &dynamic_cast<DynamicArray<People>&>(ReadSequenceFromFile(fileName, sequence));
}

void WriteSequenceToFile(std::string& fileName, Sequence<People>* sequence)
{
    std::ofstream file(fileName);
    if (!file) {
        std::cerr << "Error opening the file!" << std::endl;
        return;
    }

    auto begin = sequence->ToBegin();
    auto end = sequence->ToEnd();

    while (*begin != *end)
    {
        file << (**begin).GetLastName() << " "
            << (**begin).GetFirstName() << " "
            << (**begin).GetPatronymic() << " "
            << (**begin).GetBirthDate() << " "
            << (**begin).GetAccountBalance() << "\n";
        ++(*begin);
    }

    std::cout << "The data have been successfully written to the file " << fileName << std::endl;

    file.close();
}