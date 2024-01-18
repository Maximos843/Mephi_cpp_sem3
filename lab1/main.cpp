//
//  main.cpp
//  mephi_labs_sem3
//
//  Created by Максим Шелестов on 01.12.2023.
//

#include <iostream>
#include "DynamicArray.h"
#include "Smart_ptr.h"
#include "DynamicArrayTests.h"
#include "ArraySequenceTests.h"



int main() {
    std::cout << "Dynamic Array Tests" << std::endl;
    checker();
    std::cout << std::endl;
    std::cout << "ArraySequence Tests" << std::endl;
    checker2();
    return 0;
}
