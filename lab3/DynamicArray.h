#ifndef DynamicArray_h
#define DynamicArray_h

#include <iostream>
#include "IndexError.h"


template <class T>
class DynamicArray{
    int capacity = 0;
    int length = 0;
    T* data;

public:
    DynamicArray(int size){
        this->data = new T[size];
    };

    DynamicArray(){
        this->data = NULL;
        this->length = 0;
    };

    DynamicArray(T* items, int count){
        this->length = count;
        if (count % 10 == 0){
            capacity = 10 * (count / 10);
        }
        else{
            capacity = 10 * (count / 10 + 1);
        }
        this->data = new T[capacity];
        for (int i = 0; i < count; ++i){
            this->data[i] = items[i];
        }
    };

    DynamicArray(const DynamicArray<T>& array){
        this->length = array.GetSize();
        if (length % 10 == 0){
            capacity = 10 * (length / 10);
        }
        else{
            capacity = 10 * (length / 10 + 1);
        }
        this->data = new T[capacity];
        for (int i = 0; i < length; ++i){
            data[i] = array.Get(i);
        }
    };

    ~DynamicArray(){
        if (data != NULL){
            delete[] data;
        }
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
        return this->length;
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
        if (size % 10 == 0){
            capacity = 10 * (size / 10);
        }
        else{
            capacity = 10 * (size / 10 + 1);
        }
        T* data_new = new T[capacity];
        for (int i = 0; i < std::min(length, size); ++i){
            data_new[i] = this->data[i];
        }
        delete[] data;
        this->data = data_new;
        this->length = size;
    };

};

#endif