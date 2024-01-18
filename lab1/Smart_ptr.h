//
//  Smart_ptr.h
//  mephi_labs_sem3_cpp
//
//  Created by Максим Шелестов on 01.12.2023.
//
#ifndef Smart_ptr_h
#define Smart_ptr_h


#include <iostream>


int COUNT = 0;


template <class T>
class SmartPtr {
    T* ptr;
    int* ref_count;

public:

    SmartPtr(const SmartPtr<T>& other): ptr(other.ptr), ref_count(other.ref_count){
        (*ref_count)++;
        COUNT++;
    };

    SmartPtr(T* ptr = nullptr) : ptr(ptr), ref_count(new int(1)){
        COUNT++;
    };

    ~SmartPtr() {
        (*ref_count)--;
        COUNT--;
        if ((*ref_count) == 0) {
            delete ptr;
            delete ref_count;
        }
    };

    SmartPtr<T>& operator=(const SmartPtr<T>& other) {
        if (this != &other) {
            (*ref_count)--;
            if (*ref_count == 0) {
                delete ptr;
                delete ref_count;
            }
            ptr = other.ptr;
            ref_count = other.ref_count;
            (*ref_count)++;
        }
        return *this;
    };

    SmartPtr<T>& operator=(SmartPtr<T>* other) {
        delete ptr;
        this->ptr = other->ptr;
        this->ref_count = other->ref_count;
        (*ref_count)++;
        return *this;
    };

    SmartPtr<T>& operator=(T* other) {
        delete ptr;
        this->ptr = other;
        (*ref_count)++;
        return *this;
    };

    SmartPtr<T>& operator=(nullptr_t) {
        if (ref_count != nullptr) {
            (*ref_count)--;
            if (*ref_count == 0) {
                delete ptr;
                delete ref_count;
            }
            ptr = nullptr;
            ref_count = nullptr;
        }
        return *this;
    };

    T& operator*() {
        return *ptr;
    };

    T* operator->() {
        return ptr;
    };

    T& operator[] (int d) {
        return *(ptr + d);
    };

    T* get() const {
        return ptr;
    };
};


#endif