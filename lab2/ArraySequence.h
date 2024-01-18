//
//  ArraySequence.h
//  lab2
//
//  Created by Максим Шелестов on 13.12.2023.
//

#ifndef ArraySequence_h
#define ArraySequence_h

#include <iostream>
#include "IndexError.h"
#include "DynamicArray.h"
#include "Sequence.h"

template <class T>
class ArraySequence : public Sequence<T>{
    DynamicArray<T>* data;

public:
    ArraySequence(){
        data = new DynamicArray<T>();
    };

    ArraySequence(int size){
        data = new DynamicArray<T>(size);
    };

    ArraySequence(const DynamicArray<T>& array){
        data = new DynamicArray<T>(array);
    };

    ArraySequence(T* items, int count){
        data = new DynamicArray<T>(items, count);
    };

    ~ArraySequence(){
        delete data;
    };

    void Append(T item) override {
        data->Resize(GetLength() + 1);
        data->Set(item, GetLength() - 1);
    };

    void InsertAt(T item, int index) override {
        data->Set(item, index);
    };

    void Prepend(T item) override{
        Resize(GetLength() + 1);
        for (int i = GetLength() - 1; i > 0; --i){
            Set(data->Get(i - 1), i);
        }
        data->Set(item, 0);
    };

    T GetFirst() override {
        if (GetLength() == 0){
            throw IndexError(Empty_list);
        }
        return data->Get(0);
    };

    T GetLast() override {
        if (GetLength() == 0){
            throw IndexError(Empty_list);
        }
        return data->Get(GetLength() - 1);
    };

    T Get(int index) override {
        return data->Get(index);
    };

    int GetLength() override {
        return data->GetSize();
    };

    void Set(T item, int index) override {
        data->Set(item, index);
    };

    void Resize(int size){
        data->Resize(size);
    };

};

#endif /* ArraySequence_h */
