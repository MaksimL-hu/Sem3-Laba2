#include "DynamicArray.h"
#include "LinkedList.h"

#ifndef SORTER_H
#define SORTER_H


void SortDynamicArrayByQuickSort(DynamicArray<int>* array, double* durationSorting);
void SortDynamicArrayByHeapSort(DynamicArray<int>* array, double* durationSorting);
void SortDynamicArrayByMergeSort(DynamicArray<int>* array, double* durationSorting);
void SortLinkedListByQuickSort(LinkedList<int>* array, double* durationSorting);
void SortLinkedListByHeapSort(LinkedList<int>* array, double* durationSorting);
void SortLinkedListByMergeSort(LinkedList<int>* array, double* durationSorting);
void SortDynamicArrayByAllMethods(DynamicArray<int>* dynamicArray,
	double* durationSortingByQuickSort, double* durationSortingByHeapSort, double* durationSortingByMergeSort);
void SortLinkedListByAllMethods(LinkedList<int>* list,
	double* durationSortingByQuickSort, double* durationSortingByHeapSort, double* durationSortingByMergeSort);


#endif