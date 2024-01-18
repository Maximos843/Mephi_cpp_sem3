//
//  DynamicArray.h
//  mephi_labs_sem3_cpp
//
//  Created by Максим Шелестов on 03.12.2023.
//

#ifndef DynamicArray_h
#define DynamicArray_h

#include <iostream>
#include "IndexError.h"
#include "Smart_ptr.h"


template <class T>
class DynamicArray{
private:
    int length = 0;
    SmartPtr<T> data;

public:
    DynamicArray(int size) : length(size){
        this->data = SmartPtr<T> (new T[size]);
    };

    DynamicArray() : data(nullptr), length(0){
        COUNT++;
    };

    DynamicArray(SmartPtr<T> items, int count) : length(count){
        this->data = SmartPtr<T> (new T[length]);
        for (int i = 0; i < count; ++i){
            this->data[i] = items[i];
        }
    };

    DynamicArray(const DynamicArray<T>& array){
        this->length = array.GetSize();
        this->data = SmartPtr<T> (new T[this->length]);
        for (int i = 0; i < length; ++i){
            data[i] = array.Get(i);
        }
    };

    ~DynamicArray(){
        COUNT--;
    };

    T Get(int index){
        if (length == 0){
            throw IndexError(Empty_list);
        }
        else if (length <= index || index < 0){
            throw IndexError(Invalid_args);
        }
        else{
            return this->data[index];
        }
    };

    int GetSize(){
        return length;
    };

    void Set(T value, int index){
        if (length == 0){
            throw IndexError(Empty_list);
        }
        else if (length <= index || index < 0){
            throw IndexError(Invalid_args);
        }
        else{
            this->data[index] = value;
        }
    };

    void Resize(int size){
        SmartPtr<T> data_new = SmartPtr<T> (new T[size]);
        this->length = size;
        for (int i = 0; i < size; ++i){
            data_new[i] = this->data[i];
        }
        this->data = SmartPtr<T> (new T[size]);
        for (int i = 0; i < size; ++i){
            this->data[i] = data_new[i];
        }
    };

    T GetFirst(){
        if (length == 0){
            throw IndexError(Empty_list);
        }
        else{
            return data[0];
        }
    };

    T GetLast(){
        if (length == 0){
            throw IndexError(Empty_list);
        }
        else{
            return data[length - 1];
        }
    };

};

#endif
