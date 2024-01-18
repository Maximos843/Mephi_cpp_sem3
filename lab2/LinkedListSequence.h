//
//  LinkedListSequence.h
//  lab2
//
//  Created by Максим Шелестов on 12.12.2023.
//

#ifndef LinkedListSequence_h
#define LinkedListSequence_h

#include <iostream>
#include "IndexError.h"
#include "LinkedList.h"
#include "Sequence.h"

template <class T>
class LinkedListSequence : public Sequence<T>{
    LinkedList<T>* data;

public:
    LinkedListSequence(){
        data = new LinkedList<T>();
    };

    LinkedListSequence(T* items, int count){
        data = new LinkedList(items, count);
    };

    LinkedListSequence(const LinkedList<T>& list){
        data = new LinkedList(list);
    };

    ~LinkedListSequence(){
        delete data;
    };

    void Append(T item) override {
        data->Append(item);
    };

    void Prepend(T item) override {
        data->Prepend(item);
    };

    void InsertAt(T item, int index) override {
        data->InsertAt(item, index);
    };

    T GetFirst() override {
        return data->GetFirst();
    };

    T GetLast() override {
        return data->GetLast();
    };

    T Get(int index) override {
        return data->Get(index);
    };

    int GetLength() override {
        return data->GetLength();
    };

    void Set(T item, int index) override {
        data->Set(item, index);
    };

    LinkedListSequence<T>* GetSubList(int index1, int index2){
        LinkedList<T>* tmp = data->GetSubList(index1, index2);
        LinkedListSequence<T>* ans = new LinkedListSequence(*tmp);
        delete[] tmp;
        return ans;
    };
};


#endif /* LinkedListSequence_h */
