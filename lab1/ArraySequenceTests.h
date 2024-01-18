//
//  ArraySequenceTests.h
//  mephi_labs_sem3_cpp
//
//  Created by Максим Шелестов on 06.12.2023.
//


#ifndef ArraySequenceTests_h
#define ArraySequenceTests_h

#include <iostream>
#include "ArraySequence.h"

void Array_sequence_Get_test(){
    SmartPtr<int> a(new int[5]);
    for (int i = 0; i < 5; ++i){
        a[i] = i + 1;
    }
    ArraySequence<int> tmp(a, 5);
    for (int i = 0; i < 5; ++i){
        if (tmp.Get(i) != a[i]){
            std::cout << "Test Get failed with number\n" << i;
            return;
        }
    }
    std::cout << "All test with Get passed\n";
    return;
}

void Array_sequence_GetSize_test(){
    SmartPtr<int> a(new int[5]);
    for (int i = 0; i < 5; ++i){
        a[i] = 1;
    }
    ArraySequence<int> tmp(a, 5);
    if (tmp.GetLength() != 5){
        std::cout << "Test with Length failed\n";
        return;
    }
    std::cout << "Test with Length passed\n";
    return;
}

void Array_sequence_Set_test(){
    SmartPtr<int> a(new int[5]);
    for (int i = 0; i < 5; ++i){
        a[i] = i + 1;
    }
    ArraySequence<int> tmp(a, 5);
    for (int i = 0; i < 5; ++i){
        tmp.Set(5 - i, i);
    }
    for (int i = 0; i < 5; ++i){
        if (tmp.Get(i) != 5 - i){
            std::cout << "Test Set falied with number\n" << i;
            return;
        }
    }
    std::cout << "All Tests with Set passed\n";
    return;
}

void Array_sequence_Resize_test(){
    SmartPtr<int> a(new int[10]);
    for (int i = 0; i < 10; ++i){
        a[i] = i + 1;
    }
    ArraySequence<int> tmp(a, 10);
    tmp.Resize(4);
    if (tmp.GetLength() != 4){
        std::cout << "Test with Resize ans Size failed\n";
        return;
    }
    for (int i = 0; i < 4; ++i){
        if (tmp.Get(i) != i + 1){
            std::cout << "Test with Resize and Get failed\n";
            return;
        }
    }
    tmp.Resize(6);
    if (tmp.GetLength() != 6){
        printf("Test with Resize ans Size failed\n");
        std::cout << "Test with Resize ans Size failed\n";
        return;
    }
    for (int i = 0; i < 4; ++i){
        if (tmp.Get(i) != i + 1){
            std::cout << "Test with Resize and Get failed\n";
            return;
        }
    }
    std::cout << "All Tests with Resize passed\n";
    return;
}

void checker2(){
    std::cout << "Get\n";
    Array_sequence_Get_test();
    std::cout << "Resize\n";
    Array_sequence_Resize_test();
    std::cout << "Set\n";
    Array_sequence_Set_test();
    std::cout << "GetSize\n";
    Array_sequence_GetSize_test();
    return;
}

#endif /* ArraySequenceTests_h */
