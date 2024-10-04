#ifndef SEQUENCE_H
#define SEQUENCE_H


template <class T>
class Sequence {
public:
    virtual T GetFirstElement() = 0;
    virtual T GetLastElement() = 0;
    virtual T GetElement(int index) = 0;
    virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) = 0;
    virtual int GetLength() = 0;
    virtual void Append(T item) = 0;
    virtual void Prepend(T item) = 0;
    virtual void InsertAt(T item, int index) = 0;
    virtual void Union(Sequence<T>* list) = 0;
    virtual ~Sequence() {}
};


#endif