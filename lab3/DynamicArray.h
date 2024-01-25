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
    DynamicArray(int size) : capacity(size){
        this->data = new T[size];
    };

    DynamicArray() : data(nullptr){};

    DynamicArray(T* items, int count) : length(count){
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

    DynamicArray(const DynamicArray<T>& array) : length(array.GetSize()){
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
        if (data != nullptr){
            delete[] data;
        }
        capacity = 0;
		length = 0;
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

    void Append(T item) {
		if (length < this->capacity) {
			this->data[this->length] = item;
			this->length++;
		}
		else {
			if (this->capacity == 10) {
				this->Resize(10);
			}
			else {
				this->Resize(this->capacity + 10);
			}
			this->data[this->length] = item;
			this->length++;
		}
	}

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

    int IndexOfElem(T data){
        int left = 0;
        int right = this->length - 1;
		int mid = (left + (right - left) / 2);
		if (data == this->Get(mid)){
			return mid;
        }
		else if (left == right){
            return -1;
        }
		if (data < this->Get(mid)){
			return IndexOfElem(data);
        }
		else{
            return IndexOfElem(data);
        }
	}

    bool IsEqual(T* data, int length) {
		if (this->length != length) return false;

		for (int i = 0; i < this->length; i++)
			if (this->Get(i) != data[i]) return false;

		return true;
	}

    void PrintArray() {
		for (int i = 0; i < length; i++)
			std::cout << this->data[i] << ' ';
		std::cout << std::endl;
	}

};

#endif