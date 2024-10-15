#ifndef FILE_WORKER_H
#define FILE_WORKER_H

#include "DynamicArray.h"
#include "LinkedList.h"


void GenerateRandomNumbersFile(int count, std::string& fileName);
void ReadDynamicArrayFromFile(std::string& fileName, DynamicArray<int>* numbers);
void ReadLinkedListFromFile(std::string& fileName, LinkedList<int>* numbers);
Sequence<int>& ReadSequenceFromFile(std::string& fileName, Sequence<int>* numbers);
void WriteSequenceToFile(std::string& fileName, Sequence<int>* numbers);


#endif