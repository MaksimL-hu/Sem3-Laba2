#include "DynamicArray.h"
#include "LinkedList.h"

#ifndef FILE_RENDERER_H
#define FILE_RENDERER_H


void GenerateRandomNumbersFile(int count, std::string& fileName);
void ReadDynamicArrayFromFile(std::string& fileName, DynamicArray<int>* numbers);
void ReadLinkedListFromFile(std::string& fileName, LinkedList<int>* numbers);
void WriteDynamicArrayToFile(std::string& fileName, DynamicArray<int>* numbers);
void WriteLinkedListToFile(std::string& fileName, LinkedList<int>* numbers);


#endif