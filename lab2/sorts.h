//
//  sorts.h
//  lab2
//
//  Created by Максим Шелестов on 14.12.2023.
//

#ifndef sorts_h
#define sorts_h

#include "Sequence.h"

template<class T>
int compare(T a, T b){
    if (a < b){
        return 1;
    }
    else{
        return 0;
    }
}



template<class T>
void swap(Sequence<T>* seq, int ind1, int ind2){
    T value = seq->Get(ind1);
    seq->Set(seq->Get(ind2), ind1);
    seq->Set(value, ind2);
}

template<class T>
void BubbleSort(Sequence<T>* seq, int start, int end, int(*comp)(T, T)) {
        int size = seq->GetLength();
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size - 1; ++j) {
                if (comp(seq->Get(j), seq->Get(j + 1)) == 0) {
                    swap(seq, j, j + 1);
                }
            }
        }
}

template<class T>
void MyQuickSort(Sequence<T>* seq, int start, int end, int(*comp)(T, T)){
    if (start < end){
        int i = start;
        int j = end;
        T elem = seq->Get(((i + j) / 2));
        while (i <= j) {
            while (comp(seq->Get(i), elem)) {
                i++;
            }
            while (comp(elem, seq->Get(j))) {
                j--;
            }
            if (i <= j) {
                swap(seq, i, j);
                i++;
                j--;
            }
        }
        MyQuickSort(seq, start, j, comp);
        MyQuickSort(seq, i, end, comp);
    }
}

template<class T>
void InsertionSort(Sequence<T>* seq, int start, int end, int(*comp)(T, T)){
    T tmp;
    int item;
    for (int i = 1; i < end + 1; i++){
        tmp = seq->Get(i);
        item = i - 1;
        while (item >= 0 && comp(seq->Get(item), tmp) == 0){
            swap(seq, item + 1, item);
            item--;
        }
    }
}

template<class T>
void ShakerSort(Sequence<T>* seq, int start, int end, int(*comp)(T, T)){
    int left = 0;
    int right = end;
    int flag = 1;
    while ((left < right) && (flag > 0)){
        flag = 0;
        for (int i = left; i < right; i++) {
            if (comp(seq->Get(i), seq->Get(i + 1)) == 0) {
                swap(seq, i, i + 1);
                flag = 1;
            }
        }
        right--;
        for (int i = right; i > left; i--){
            if (comp(seq->Get(i - 1), seq->Get(i)) == 0) {
                swap(seq, i, i - 1);
                flag = 1;
            }
        }
        left++;
    }
}

#endif /* sorts_h */