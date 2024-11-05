#ifndef FILE_WORKER_H
#define FILE_WORKER_H

#include "DynamicArray.h"
#include "LinkedList.h"
#include "People.h"

void GenerateRandomFile(int count, std::string& fileName);
void ReadDynamicArrayFromFile(std::string& fileName, DynamicArray<People>* numbers);
Sequence<People>& ReadSequenceFromFile(std::string& fileName, Sequence<People>* numbers);
void WriteSequenceToFile(std::string& fileName, Sequence<People>* numbers);

#endif