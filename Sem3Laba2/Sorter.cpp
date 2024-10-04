#include <chrono>
#include <iostream>

#include "DynamicArray.h"
#include "LinkedList.h"

void SortDynamicArrayByQuickSort(DynamicArray<int>* array, double* durationSorting)
{
	auto start = std::chrono::high_resolution_clock::now();
	array->QuickSort();
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration = end - start;
	*durationSorting = duration.count();
}

void SortDynamicArrayByHeapSort(DynamicArray<int>* array, double* durationSorting)
{
	auto start = std::chrono::high_resolution_clock::now();
	array->HeapSort();
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration_time = end - start;
	*durationSorting = duration_time.count();
}

void SortDynamicArrayByMergeSort(DynamicArray<int>* array, double* durationSorting)
{
	auto start = std::chrono::high_resolution_clock::now();
	array->MergeSort();
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration_time = end - start;
	*durationSorting = duration_time.count();
}

void SortLinkedListByQuickSort(LinkedList<int>* array, double* durationSorting)
{
	auto start = std::chrono::high_resolution_clock::now();
	array->QuickSort();
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration_time = end - start;
	*durationSorting = duration_time.count();
}

void SortLinkedListByHeapSort(LinkedList<int>* array, double* durationSorting)
{
	auto start = std::chrono::high_resolution_clock::now();
	array->HeapSort();
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<float> duration_time = end - start;
	*durationSorting = duration_time.count();
}

void SortLinkedListByMergeSort(LinkedList<int>* array, double* durationSorting)
{
	auto start = std::chrono::high_resolution_clock::now();
	array->MergeSort();
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration_time = end - start;
	*durationSorting = duration_time.count();
}

void SortDynamicArrayByAllMethods(DynamicArray<int>* dynamicArray,
	double* durationSortingByQuickSort, double* durationSortingByHeapSort, double* durationSortingByMergeSort)
{
	DynamicArray<int> copy;

	for (int i = 0; i < dynamicArray->GetLength(); i++)
	{
		copy.Append(dynamicArray->GetElement(i));
	}

	SortDynamicArrayByQuickSort(&copy, durationSortingByQuickSort);

	for (int i = 0; i < dynamicArray->GetLength(); i++)
	{
		copy[i] = dynamicArray->GetElement(i);
	}

	SortDynamicArrayByHeapSort(&copy, durationSortingByHeapSort);
	SortDynamicArrayByMergeSort(dynamicArray, durationSortingByMergeSort);
}

void SortLinkedListByAllMethods(LinkedList<int>* list,
	double* durationSortingByQuickSort, double* durationSortingByHeapSort, double* durationSortingByMergeSort)
{
	LinkedList<int> copy1;
	LinkedList<int> copy2;

	for (int i = 0; i < list->GetLength(); i++)
	{
		copy1.Append(list->GetElement(i));
		copy2.Append(list->GetElement(i));
	}

	SortLinkedListByQuickSort(&copy1, durationSortingByQuickSort);
	SortLinkedListByHeapSort(&copy2, durationSortingByHeapSort);
	SortLinkedListByMergeSort(list, durationSortingByMergeSort);
}