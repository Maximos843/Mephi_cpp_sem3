//
//  DynamicArrayTests.h
//  mephi_labs_sem3_cpp
//
//  Created by Максим Шелестов on 06.12.2023.
//


#ifndef DynamicArrayTests_h
#define DynamicArrayTests_h

#include <iostream>
#include "DynamicArray.h"

void Get_test(){
    SmartPtr<int> a(new int[5]);
    for (int i = 0; i < 5; ++i){
        a[i] = i + 1;
    }
    DynamicArray<int>* tmp = new DynamicArray<int>(a, 5);
    for (int i = 0; i < 5; ++i){
        if (tmp->Get(i) != a[i]){
            std::cout << "Test Get failed with number\n" << i;
            return;
        }
    }
    std::cout << "All test with Get passed\n";
    return;
}

void GetSize_test(){
    SmartPtr<int> a(new int[5]);
    for (int i = 0; i < 5; ++i){
        a[i] = 1;
    }
    DynamicArray<int>* tmp = new DynamicArray<int>(a, 5);
    if (tmp->GetSize() != 5){
        std::cout << "Test with Length failed\n";
        return;
    }
    std::cout << "Test with Length passed\n";
    return;
}

void Set_test(){
    SmartPtr<int> a(new int[5]);
    for (int i = 0; i < 5; ++i){
        a[i] = i + 1;
    }
    DynamicArray<int>* tmp = new DynamicArray<int>(a, 5);
    for (int i = 0; i < 5; ++i){
        tmp->Set(5 - i, i);
    }
    for (int i = 0; i < 5; ++i){
        if (tmp->Get(i) != 5 - i){
            std::cout << "Test Set falied with number\n" << i;
            return;
        }
    }
    std::cout << "All Tests with Set passed\n";
    return;
}

void Resize_test(){
    SmartPtr<int> a(new int[10]);
    for (int i = 0; i < 10; ++i){
        a[i] = i + 1;
    }
    DynamicArray<int>* tmp = new DynamicArray<int>(a, 10);
    tmp->Resize(4);
    if (tmp->GetSize() != 4){
        std::cout << "Test with Resize ans Size failed\n";
        return;
    }
    for (int i = 0; i < 4; ++i){
        if (tmp->Get(i) != i + 1){
            std::cout << "Test with Resize and Get failed\n";
            return;
        }
    }
    tmp->Resize(6);
    if (tmp->GetSize() != 6){
        printf("Test with Resize ans Size failed\n");
        std::cout << "Test with Resize ans Size failed\n";
        return;
    }
    for (int i = 0; i < 4; ++i){
        if (tmp->Get(i) != i + 1){
            std::cout << "Test with Resize and Get failed\n";
            return;
        }
    }
    std::cout << "All Tests with Resize passed\n";
    return;
}

void checker(){
    std::cout << "Get\n";
    Get_test();
    std::cout << "Resize\n";
    Resize_test();
    std::cout << "Set\n";
    Set_test();
    std::cout << "GetSize\n";
    GetSize_test();
    return;
}

#endif /* DynamicArrayTests_h */
