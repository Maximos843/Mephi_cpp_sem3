//
//  Sequence.h
//  lab2
//
//  Created by Максим Шелестов on 10.12.2023.
//

#ifndef Sequence_h
#define Sequence_h


template <class T>
class Sequence{
public:
    virtual void Append(T item) = 0;
    virtual void Prepend(T item) = 0;
    virtual void InsertAt(T item, int index) = 0;
    virtual T GetFirst() = 0;
    virtual T GetLast() = 0;
    virtual T Get(int index) = 0;
    virtual int GetLength() = 0;
    virtual void Set(T value, int index) = 0;
};

#endif /* Sequence_h */
