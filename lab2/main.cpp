//
//  main.cpp
//  lab2
//
//  Created by Максим Шелестов on 10.12.2023.
//

#include <iostream>
#include "sort_tests.h"
#include "sorts.h"
#include "menu_functions.hpp"


int main() {
    printmenu();
    int n, size, sort_algo, data_type;
    std::cin >> n;
    switch (n){
        case 1:
        {
            std::cout << "Enter Size to check sort\n";
            std::cin >> size;
            int* a = new int[size];
            for (int i = 0; i < size; ++i){
                int item = rand() % 1000;
                a[i] = item;
            }
            ArraySequence<int> arr = ArraySequence<int>(a, size);
            print<int>(&arr);
            std::cout << "Choose sort algo:\n1. quick\n2. bubble\n3. insert\n4. shaker\n";
            std::cin >> sort_algo;
            switch (sort_algo){
            case 1:
                MyQuickSort<int>(&arr, 0, size - 1, compare<int>);
                break;
            case 2:
                BubbleSort<int>(&arr, 0, size - 1, compare<int>);
                break;
            case 3:
                InsertionSort<int>(&arr, 0, size - 1, compare<int>);
                break;
            case 4:
                ShakerSort<int>(&arr, 0, size - 1, compare<int>);
                break;
            default:
                break;
            }
            print<int>(&arr);
            delete [] a;
            break;
        }
        case 2:
            {
            std::cout << "Enter Size to check sort\n";
            std::cin >> size;
            int* a = new int[size];
            for (int i = 0; i < size; ++i){
                int item = rand() % 1000;
                a[i] = item;
            }
            LinkedListSequence<int> arr = LinkedListSequence<int>(a, size);
            print<int>(&arr);
            std::cout << "Choose sort algo:\n1. quick\n2. bubble\n3. insert\n4. shaker\n";
            std::cin >> sort_algo;
            switch (sort_algo){
            case 1:
                MyQuickSort<int>(&arr, 0, size - 1, compare<int>);
                break;
            case 2:
                BubbleSort<int>(&arr, 0, size - 1, compare<int>);
                break;
            case 3:
                InsertionSort<int>(&arr, 0, size - 1, compare<int>);
                break;
            case 4:
                ShakerSort<int>(&arr, 0, size - 1, compare<int>);
                break;
            default:
                break;
            }
            print<int>(&arr);
            delete [] a;
            break;
            }
        case 3:
        {
            std::cout << "Choose data type:\n1. int\n2. double\n";
            std::cin >> data_type;
            if (data_type == 1){
                std::cout << "\nShakerSort tests\n";
                go_tests<int>(ShakerSort<int>, compare<int>);
                std::cout << "\nInsertionSort tests\n";
                go_tests<int>(InsertionSort<int>, compare<int>);
                std::cout << "\nBubbleSort tests\n";
                go_tests<int>(BubbleSort<int>, compare<int>);
                std::cout << "\nMyQuickSort tests\n";
                go_tests<int>(MyQuickSort<int>, compare<int>);
            }
            else if (data_type == 2){
                std::cout << "\nShakerSort tests\n";
                go_tests<double>(ShakerSort<double>, compare<double>);
                std::cout << "\nInsertionSort tests\n";
                go_tests<double>(InsertionSort<double>, compare<double>);
                std::cout << "\nBubbleSort tests\n";
                go_tests<double>(BubbleSort<double>, compare<double>);
                std::cout << "\nMyQuickSort tests\n";
                go_tests<double>(MyQuickSort<double>, compare<double>);
            }
            else{
                std::cout << "Incorrect input\n";
            }
            break;
        }
        case 4:
        {
            std::cout << "Choose sort:\n1. quick\n2. bubble\n3. insert\n4. shaker\n";
            std::cin >> sort_algo;
            switch (sort_algo){
                case 1:
                    SortTime(MyQuickSort<int>, compare<int>);
                    break;
                case 2:
                    SortTime(BubbleSort<int>, compare<int>);
                    break;
                case 3:
                    SortTime(InsertionSort<int>, compare<int>);
                    break;
                case 4:
                    SortTime(ShakerSort<int>, compare<int>);
                    break;
                default:
                    break;
            }
            break;
        }
        case 5:
            break;
        default:
            break;
    }
    return 0;
}
