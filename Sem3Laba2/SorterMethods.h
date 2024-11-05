#ifndef SORTER_METHODS_H
#define SORTER_METHODS_H

#include <chrono>

#include "DynamicArray.h"
#include "LinkedList.h"
#include "Sorter.h"

template<typename T>
void SortSequenceByQuickSort(Sequence<T>* array, double* durationSorting)
{
	Sorter<T> sorter;
	auto start = std::chrono::high_resolution_clock::now();
	sorter.QuickSort(array);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration = end - start;
	*durationSorting = duration.count();
}

template<typename T>
void SortSequenceByHeapSort(Sequence<T>* array, double* durationSorting)
{
	Sorter<T> sorter;
	auto start = std::chrono::high_resolution_clock::now();
	sorter.HeapSort(array);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration = end - start;
	*durationSorting = duration.count();
}

template<typename T>
void SortSequenceByMergeSort(Sequence<T>* array, double* durationSorting)
{
	Sorter<T> sorter;
	auto start = std::chrono::high_resolution_clock::now();
	sorter.MergeSort(array);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration = end - start;
	*durationSorting = duration.count();
}

template<typename T>
void SortDynamicArrayByAllMethods(DynamicArray<T>* dynamicArray,
	double* durationSortingByQuickSort, double* durationSortingByHeapSort, double* durationSortingByMergeSort)
{
	int length = dynamicArray->GetLength();
	DynamicArray<T> copy1(length);
	DynamicArray<T> copy2(length);

	for (int i = 0; i < length; i++)
	{
		copy1[i] = dynamicArray->GetElement(i);
		copy2[i] = dynamicArray->GetElement(i);
	}

	SortSequenceByQuickSort(&copy1, durationSortingByQuickSort);
	SortSequenceByHeapSort(&copy2, durationSortingByHeapSort);
	SortSequenceByMergeSort(dynamicArray, durationSortingByMergeSort);
}

#endif