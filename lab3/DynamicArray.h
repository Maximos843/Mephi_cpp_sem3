#ifndef DynamicArray_h
#define DynamicArray_h

#include <iostream>
#include "IndexError.h"


template <class T>
class DynamicArray{
    int size = 0;
    int length = 0;
    T* data;

public:
    DynamicArray(int size) : size(size){
        this->data = new T[size];
    };

    DynamicArray() : data(nullptr){};

    DynamicArray(T* items, int count) : DynamicArray(count){
        for (int i = 0; i < count; ++i){
            this->data[i] = items[i];
        }
        length = count;
    };

    DynamicArray(const DynamicArray<T>& array, int length) : DynamicArray(length){
        for (int i = 0; i < length; ++i){
            data[i] = array.Get(i);
        }
        this->length = length;
    };

    DynamicArray(const DynamicArray<T>& array) : DynamicArray(array.data, array.length) {};

    ~DynamicArray(){
        delete[] data;
        size = 0;
		length = 0;
    };

    T Get(int index){
        if (length == 0){
            throw std::length_error(SIZE_LOWER_ZERO);
        }
        else if (length <= index || index < 0){
            throw std::out_of_range(INDEX_OUT_OF_RANGE);
        }
        return this->data[index];
    };

    int GetSize(){
        return this->size;
    };

    int GetLength(){
        return this->length;
    };

    void Set(T value, int index){
        if (length == 0){
            throw std::length_error(SIZE_LOWER_ZERO);
        }
        else if (length <= index || index < 0){
            throw std::out_of_range(INDEX_OUT_OF_RANGE);
        }
        this->data[index] = value;
    };

    void Append(T item) {
		if (this->length < this->size) {
			this->data[this->length] = item;
			this->length++;
		}
		else {
			if (this->size == 0) {
				this->Resize(10);
			}
			else {
				this->Resize(this->size + 10);
			}
			this->data[this->length] = item;
			this->length++;
		}
	}

    void Resize(int size){
        if (size <= 0){
            throw std::length_error(SIZE_LOWER_ZERO);
        }
        T* data_new = new T[size];
        for (int i = 0; i < std::min(this->size, size); ++i){
            data_new[i] = this->data[i];
        }
        delete[] data;
        this->data = data_new;
        if (this->length > size){
            this->length = size;
        }
        this->size = size;
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
};

#endif