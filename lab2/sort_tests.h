//
//  sort_tests.h
//  lab2
//
//  Created by Максим Шелестов on 19.12.2023.
//

#ifndef sort_test2_h
#define sort_test2_h

#include "Sequence.h"
#include "ArraySequence.h"
#include "LinkedListSequence.h"
#include <iostream>
#include <random>
#include <ctime>
#include "chrono"

template<class T>
bool compare_sequence(Sequence<T>* a, Sequence<T>* b){
    int n = a->GetLength();
    if (n == b->GetLength()){
        for (int i = 0; i < n; i++){
            if (a->Get(i) != b->Get(i)){
                return false;
            }
        }
        return true;
    }
    return false;
}

template<class T>
void test1(void (*sort)(Sequence<T>* seq, int start, int end, int(*compare)(T,T)), int(*compare)(T, T)){
    T a[6] = {1, 2, 3, 4, 5, 6};
    ArraySequence<T> sorted = ArraySequence<T>(a, 6);
    ArraySequence<T> seq = ArraySequence<T>(a, 6);
    sort(&sorted, 0, sorted.GetLength() - 1, compare);
    if (compare_sequence(&seq, &sorted)){
        std::cout << "test1: array in direct order - completed successfully\n";
    }
    else{
        std::cout << "test1: array in direct order - completed not successfully\n";
    }
    LinkedListSequence<T> sorted_list = LinkedListSequence<T>(a, 6);
    LinkedListSequence<T> seq_list = LinkedListSequence<T>(a, 6);
    sort(&sorted_list, 0, sorted.GetLength() - 1, compare);
    if (compare_sequence(&seq_list, &sorted_list)){
        std::cout << "test1: list in direct order - completed successfully\n";
    }
    else{
        std::cout << "test1: list in direct order - completed not successfully\n";
    }
}

template<class T>
void test2(void (*sort)(Sequence<T>* seq, int start, int end, int(*compare)(T,T)), int(*compare)(T, T)){
    T a[6] = {1, 1, 1, 1, 1, 1};
    ArraySequence<T> sorted = ArraySequence<T>(a, 6);
    ArraySequence<T> seq = ArraySequence<T>(a, 6);
    sort(&sorted, 0, sorted.GetLength() - 1, compare);
    if (compare_sequence(&seq, &sorted)){
        std::cout << "test2: array of one value - completed successfully\n";
    }
    else{
        std::cout << "test2: array of one value - completed not successfully\n";
    }
    LinkedListSequence<T> sorted_list = LinkedListSequence<T>(a, 6);
    LinkedListSequence<T> seq_list = LinkedListSequence<T>(a, 6);
    sort(&sorted_list, 0, sorted.GetLength() - 1, compare);
    if (compare_sequence(&seq_list, &sorted_list)){
        std::cout << "test2: list of one value - completed successfully\n";
    }
    else{
        std::cout << "test2: list of one value - completed not successfully\n";
    }
}

template<class T>
void test3(void (*sort)(Sequence<T>* seq, int start, int end, int(*compare)(T,T)), int(*compare)(T, T)){
    T a[6] = {6, 5, 4, 3, 2, 1};
    T b[6] = {1, 2, 3, 4, 5, 6};
    ArraySequence<T> sorted = ArraySequence<T>(a, 6);
    ArraySequence<T> seq = ArraySequence<T>(b, 6);
    sort(&sorted, 0, sorted.GetLength() - 1, compare);
    if (compare_sequence(&seq, &sorted)){
        std::cout << "test3: array in indirect order - completed successfully\n";
    }
    else{
        //for (int i = 0; i < 6; i++){
        //   std::cout << sorted.Get(i) << " ";
        //}
        std::cout << "test3: array in indirect order - completed not successfully\n";
    }
    LinkedListSequence<T> sorted_list = LinkedListSequence<T>(a, 6);
    LinkedListSequence<T> seq_list = LinkedListSequence<T>(b, 6);
    sort(&sorted_list, 0, sorted_list.GetLength() - 1, compare);
    if (compare_sequence(&seq_list, &sorted_list)){
        std::cout << "test3: list in indirect order - completed successfully\n";
    }
    else{
        std::cout << "test3: list in indirect order - completed not successfully\n";
    }
}

template<class T>
void test4(void (*sort)(Sequence<T>* seq, int start, int end, int(*compare)(T,T)), int(*compare)(T, T)){
    T a[6] = {1, 5, 4, 1234, 2, 1};
    T b[6] = {1, 1, 2, 4, 5, 1234};
    ArraySequence<T> sorted = ArraySequence<T>(a, 6);
    ArraySequence<T> seq = ArraySequence<T>(b, 6);
    sort(&sorted, 0, sorted.GetLength() - 1, compare);
    if (compare_sequence(&seq, &sorted)){
        std::cout << "test4: array random order - completed successfully\n";
    }
    else{
        std::cout << "test4: array random order - completed not successfully\n";
    }
    LinkedListSequence<T> sorted_list = LinkedListSequence<T>(a, 6);
    LinkedListSequence<T> seq_list = LinkedListSequence<T>(b, 6);
    sort(&sorted_list, 0, sorted_list.GetLength() - 1, compare);
    if (compare_sequence(&seq_list, &sorted_list)){
        std::cout << "test4: list random order - completed successfully\n";
    }
    else{
        std::cout << "test4: list random order - completed not successfully\n";
    }
}

template<class T>
void go_tests(void (*sort)(Sequence<T>* seq, int start, int end, int(*compare)(T,T)), int(*compare)(T, T)){
    test1<T>(sort, compare);
    test2<T>(sort, compare);
    test3<T>(sort, compare);
    test4<T>(sort, compare);
}

ArraySequence<int>* generateSequence(int size){
    std::mt19937 rng(std::time(nullptr));
    std::uniform_int_distribution<int> dist(1, 100);
    int* a = new int[size];
    for (int i = 0; i < size; i++){
        int random_number = dist(rng);
        a[i] = random_number;
    }
    ArraySequence<int>* seq = new ArraySequence<int>(a, size);
    return seq;
}

void SortTime(void (*sort)(Sequence<int>* seq, int start, int end, int(*compare)(int, int)), int(*compare)(int, int)){
    for(int i = 10; i < 1000011; i += 50000){
        ArraySequence<int>* seq = generateSequence(i);
        auto t_start = std::chrono::high_resolution_clock::now();
        sort(seq, 0, i - 1, compare);
        const auto t_end = std::chrono::high_resolution_clock::now();
        std::cout << "count: " << i << "  time: ";
        std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(t_end - t_start).count() << '\n';
    }
}

#endif /* sort_tests_h */
