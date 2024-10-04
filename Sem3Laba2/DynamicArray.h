#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include "Sequence.h"


template <class T>
class DynamicArray : public Sequence<T>
{
private:
    T* data;
    int size;

    void Resize(int newSize)
    {
        T* newData = new T[newSize];

        int minSize = (newSize < size) ? newSize : size;

        for (int i = 0; i < minSize; ++i)
        {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
        size = newSize;
    }

    void Set(int index, T value)
    {
        data[index] = value;
    }

    void Swap(T& a, T& b)
    {
        T temp = a;
        a = b;
        b = temp;
    }

    int Separation(int low, int high)
    {
        T pivot = data[high];
        int i = low - 1;

        for (int j = low; j < high; j++)
        {
            if (data[j] <= pivot) 
            {
                i++;
                Swap(data[i], data[j]);
            }
        }

        i += 1;

        Swap(data[i], data[high]);

        return i;
    }

    void SiftDown(int n, int i)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && data[left] > data[largest])
        {
            largest = left;
        }

        if (right < n && data[right] > data[largest])
        {
            largest = right;
        }

        if (largest != i)
        {
            Swap(data[i], data[largest]);
            SiftDown(n, largest);
        }
    }

    void Merge(int low, int middle, int high) {
        int size1 = middle - low + 1;
        int size2 = high - middle;

        DynamicArray<T> array1(size1);
        DynamicArray<T> array2(size1);

        for (int i = 0; i < size1; i++)
        {
            array1[i] = data[low + i];
        }
        for (int i = 0; i < size2; i++)
        {
            array2[i] = data[middle + 1 + i];
        }

        int i = 0, j = 0, k = low;

        while (i < size1 && j < size2) {
            if (array1[i] <= array2[j]) 
            {
                data[k] = array1[i];
                i++;
            }
            else 
            {
                data[k] = array2[j];
                j++;
            }

            k++;
        }

        while (i < size1) 
        {
            data[k] = array1[i];
            i++;
            k++;
        }

        while (j < size2) 
        {
            data[k] = array2[j];
            j++;
            k++;
        }
    }

public:
    DynamicArray() : size(0) {}

    DynamicArray(T* items, int size)
    {
        this->size = size;
        data = new T[size];

        for (int i = 0; i < size; ++i)
        {
            Set(i, items[i]);
        }
    }

    DynamicArray(int size)
    {
        this->size = size;
        data = new T[size];
    }

    DynamicArray(DynamicArray<T>& dynamicArray)
    {
        size = dynamicArray.size;
        data = new T[size];

        for (int i = 0; i < size; ++i)
        {
            Set(i, dynamicArray.data[i]);
        }
    }

    ~DynamicArray()
    {
        delete[] data;
    }

    T& operator[](int index)
    {
        return data[index];
    }

    T GetFirstElement() override
    {
        return GetElement(0);
    }

    T GetLastElement() override
    {
        return GetElement(size - 1);
    }

    T GetElement(int index) override
    {
        return data[index];
    }

    DynamicArray<T>* GetSubsequence(int startIndex, int endIndex) override
    {
        if (startIndex > endIndex)
        {
            return NULL;
        }

        int length;

        if (endIndex > size)
        {
            length = size - startIndex;
        }
        else
        {
            length = endIndex - startIndex + 1;

            if (startIndex == 0)
            {
                length -= 1;
            }
        }

        T* items = new T[length];

        for (int i = 0; i < length; i++)
        {
            items[i] = GetElement(startIndex + i);
        }

        return new DynamicArray<T>(items, length);
    }

    int GetLength() override 
    {
        return size;
    }

    void Append(T data) override 
    {
        InsertAt(data, size);
    }

    void Prepend(T data) override
    {
        InsertAt(data, 0);
    }

    void InsertAt(T data, int index) override
    {
        Resize(size + 1);

        for (int i = size - 1; i > index; i--)
        {
            Set(i, GetElement(i - 1));
        }

        Set(index, data);
    }

    void Union(Sequence<T>* dynamicArray) override
    {
        int oldSize = size;

        for (int i = 0; i < dynamicArray->GetLength(); i++)
        {
            Append(dynamicArray->GetElement(i));
        }
    }

    void QuickSort(int low, int high) 
    {
        if (low < high)
        {
            int pivot = Separation(low, high);

            QuickSort(low, pivot - 1);
            QuickSort(pivot + 1, high);
        }
    }

    void QuickSort()
    {
        QuickSort(0, size - 1);
    }

    void HeapSort()
    {
        int n = size;

        for (int i = n / 2 - 1; i >= 0; i--)
        {
            SiftDown(n, i);
        }

        for (int i = n - 1; i > 0; i--)
        {
            Swap(data[0], data[i]);

            SiftDown(i, 0);
        }
    }

    void MergeSort(int low, int high)
    {
        if (low < high)
        {
            int middle = low + (high - low) / 2;

            MergeSort(low, middle);
            MergeSort(middle + 1, high);

            Merge(low, middle, high);
        }
    }

    void MergeSort()
    {
        MergeSort(0, size - 1);
    }
};


#endif