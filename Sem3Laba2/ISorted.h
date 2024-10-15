#ifndef ISORTED_H
#define ISORTED_H


template <class T>
class ISorted {
public:
    virtual void QuickSort(Sequence<T>* sequence) = 0;
    virtual void HeapSort(Sequence<T>* sequence) = 0;
    virtual void MergeSort(Sequence<T>* sequence) = 0;
    virtual ~ISorted() {}
};


#endif