//
//  ArraySequence.h
//  mephi_labs_sem3_cpp
//
//  Created by Максим Шелестов on 04.12.2023.
//

#ifndef ArraySequence_h
#define ArraySequence_h

#include <iostream>
#include "Smart_ptr.h"

template <class T> class ArraySequence {
private:

    DynamicArray<T> *array;
public:

    ArraySequence() {
        array = new DynamicArray<T>();
    }

    ArraySequence(SmartPtr<T> items, int count) {
        array = new DynamicArray<T>(items, count);
    }

    ArraySequence(const DynamicArray<T> &dynamicArray) {
        array = new DynamicArray<T>(dynamicArray);
    }

    ~ArraySequence() {
        delete array;
    }

    void Set(T value, int index) {
        array->Set(value, index);
    }

    void Resize(int newSize) {
        array->Resize(newSize);
    }

    void Append(T item) {
        array->Set(item, array->length);
    }

    void Prepend(T item) {
        array->Set(item, 0);
    }

    T Get(int index) {
        return array->Get(index);
    }

    int GetLength() {
        return array->GetSize();
    }

    T GetFirst() {
        return array->GetFirst();
    }

    T GetLast() {
        return array->GetLast();
    }

    DynamicArray<T> *GetData() {
        return array;
    }
};

#endif