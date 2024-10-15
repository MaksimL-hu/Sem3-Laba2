#include <chrono>
#include <iostream>

#include "DynamicArray.h"
#include "LinkedList.h"
#include "Sorter.h"


void SortSequenceByQuickSort(Sequence<int>* array, double* durationSorting)
{
	Sorter<int> sorter;
	auto start = std::chrono::high_resolution_clock::now();
	sorter.QuickSort(array);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration = end - start;
	*durationSorting = duration.count();
}

void SortDynamicArrayByQuickSort(DynamicArray<int>* array, double* durationSorting)
{
	SortSequenceByQuickSort(array, durationSorting);
}

void SortLinkedListByQuickSort(LinkedList<int>* array, double* durationSorting)
{
	SortSequenceByQuickSort(array, durationSorting);
}

void SortSequenceByHeapSort(Sequence<int>* array, double* durationSorting)
{
	Sorter<int> sorter;
	auto start = std::chrono::high_resolution_clock::now();
	sorter.HeapSort(array);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration = end - start;
	*durationSorting = duration.count();
}

void SortDynamicArrayByHeapSort(DynamicArray<int>* array, double* durationSorting)
{
	SortSequenceByHeapSort(array, durationSorting);
}

void SortLinkedListByHeapSort(LinkedList<int>* array, double* durationSorting)
{
	SortSequenceByHeapSort(array, durationSorting);
}

void SortSequenceByMergeSort(Sequence<int>* array, double* durationSorting)
{
	Sorter<int> sorter;
	auto start = std::chrono::high_resolution_clock::now();
	sorter.MergeSort(array);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration = end - start;
	*durationSorting = duration.count();
}

void SortDynamicArrayByMergeSort(DynamicArray<int>* array, double* durationSorting)
{
	SortSequenceByMergeSort(array, durationSorting);
}

void SortLinkedListByMergeSort(LinkedList<int>* array, double* durationSorting)
{
	SortSequenceByMergeSort(array, durationSorting);
}

void SortDynamicArrayByAllMethods(DynamicArray<int>* dynamicArray,
	double* durationSortingByQuickSort, double* durationSortingByHeapSort, double* durationSortingByMergeSort)
{
	DynamicArray<int> copy;

	for (int i = 0; i < dynamicArray->GetLength(); i++)
	{
		copy.Append(dynamicArray->GetElement(i));
	}

	SortSequenceByQuickSort(&copy, durationSortingByQuickSort);

	for (int i = 0; i < dynamicArray->GetLength(); i++)
	{
		copy[i] = dynamicArray->GetElement(i);
	}

	SortSequenceByHeapSort(&copy, durationSortingByHeapSort);
	SortSequenceByMergeSort(dynamicArray, durationSortingByMergeSort);
}

void SortLinkedListByAllMethods(LinkedList<int>* list,
	double* durationSortingByQuickSort, double* durationSortingByHeapSort, double* durationSortingByMergeSort)
{
	DynamicArray<int> copy;

	for (int i = 0; i < list->GetLength(); i++)
	{
		copy.Append(list->GetElement(i));
	}

	SortSequenceByQuickSort(&copy, durationSortingByQuickSort);

	for (int i = 0; i < list->GetLength(); i++)
	{
		copy[i] = list->GetElement(i);
	}

	SortSequenceByHeapSort(&copy, durationSortingByHeapSort);
	SortSequenceByMergeSort(list, durationSortingByMergeSort);
}

