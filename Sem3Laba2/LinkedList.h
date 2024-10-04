#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Sequence.h"


template <class T>
class LinkedList : public Sequence<T>
{
private:
    struct Node
    {
        T data;
        Node* next;

        Node(T data, Node* next = nullptr) : data(data), next(next) {}
    };

    Node* head;
    Node* tail;
    int length;

    void Swap(Node* node1, Node* node2)
    {
        T tempData = node1->data;

        node1->data = node2->data;
        node2->data = tempData;
    }

    void Set(int index, T value)
    {
        Node* current = head;

        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }

        current->data = value;
    }

    int Separation(int low, int high)
    {
        T pivot = GetElement(high);
        int i = low - 1;

        for (int j = low; j < high; j++)
        {
            if (GetElement(j) <= pivot)
            {
                i++;
                Swap(GetNode(i), GetNode(j));
            }
        }

        i += 1;

        Swap(GetNode(i), GetNode(high));

        return i;
    }

    void SiftDown(int n, int i)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && GetElement(left) > GetElement(largest))
        {
            largest = left;
        }

        if (right < n && GetElement(right) > GetElement(largest))
        {
            largest = right;
        }

        if (largest != i)
        {
            Swap(GetNode(i), GetNode(largest));
            SiftDown(n, largest);
        }
    }

    void Merge(int low, int middle, int high) {
        int size1 = middle - low + 1;
        int size2 = high - middle;

        LinkedList<T> array1;
        LinkedList<T> array2;

        for (int i = 0; i < size1; i++)
        {
            array1.Append(GetElement(low + i));
        }
        for (int i = 0; i < size2; i++)
        {
            array2.Append(GetElement(middle + 1 + i));
        }

        int i = 0, j = 0, k = low;

        while (i < size1 && j < size2) {
            if (array1.GetElement(i) <= array2.GetElement(j))
            {
                Set(k, array1.GetElement(i));
                i++;
            }
            else
            {
                Set(k, array2.GetElement(j));
                j++;
            }

            k++;
        }

        while (i < size1)
        {
            Set(k, array1.GetElement(i));
            i++;
            k++;
        }

        while (j < size2)
        {
            Set(k, array2.GetElement(j));
            j++;
            k++;
        }
    }

public:

    LinkedList() : head(nullptr), tail(nullptr), length(0) {}

    LinkedList(T* items, int count) : head(nullptr), tail(nullptr), length(0)
    {
        for (int i = 0; i < count; ++i)
        {
            Append(items[i]);
        }
    }

    LinkedList(LinkedList<T>& list) : head(nullptr), tail(nullptr), length(0)
    {
        Node* current = list.head;

        while (current != nullptr)
        {
            Append(current->data);
            current = current->next;
        }
    }

    ~LinkedList()
    {
        Node* current = head;
        Node* next;

        while (current != nullptr)
        {
            next = current->next;
            delete current;
            current = next;
        }
    }

    T GetFirstElement() override
    {
        return head->data;
    }

    T GetLastElement() override
    {
        return tail->data;
    }

    T GetElement(int index) override
    {
        return GetNode(index)->data;
    }

    Node* GetNode(int index)
    {
        Node* current = head;

        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }

        return current;
    }

    LinkedList<T>* GetSubsequence(int startIndex, int endIndex) override
    {
        if (endIndex >= length)
        {
            endIndex = length - 1;
        }

        LinkedList<T>* sublist = new LinkedList<T>();
        Node* current = head;

        for (int i = 0; i <= endIndex; i++)
        {
            if (i >= startIndex)
            {
                sublist->Append(current->data);
            }

            current = current->next;
        }

        return sublist;
    }

    int GetLength() override
    {
        return length;
    }

    void Append(T item) override
    {
        Node* newNode = new Node(item);

        if (length == 0)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        length++;
    }

    void Prepend(T item) override
    {
        Node* newNode = new Node(item, head);

        if (length == 0)
        {
            head = tail = newNode;
        }
        else
        {
            head = newNode;
        }

        length++;
    }

    void InsertAt(T item, int index) override
    {
        if (index == 0)
        {
            Prepend(item);
        }
        else if (index == length)
        {
            Append(item);
        }
        else
        {
            Node* current = head;

            for (int i = 0; i < index - 1; ++i)
            {
                current = current->next;
            }

            Node* newNode = new Node(item, current->next);
            current->next = newNode;
            length++;
        }
    }

    void Union(Sequence<T>* list) override
    {
        int length = list->GetLength();

        for (int i = 0; i < length; i++)
        {
            Append(list->GetElement(i));
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
        QuickSort(0, length - 1);
    }

    void HeapSort()
    {
        int n = length;

        for (int i = n / 2 - 1; i >= 0; i--)
        {
            SiftDown(n, i);
        }

        for (int i = n - 1; i > 0; i--)
        {
            Swap(GetNode(0), GetNode(i));

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
        MergeSort(0, length - 1);
    }
};


#endif