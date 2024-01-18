//
//  menu_functions.hpp
//  lab2
//
//  Created by Максим Шелестов on 17.12.2023.
//

#ifndef menu_functions_hpp
#define menu_functions_hpp

#include <iostream>
#include "Sequence.h"


template<typename T>
void print(Sequence<T>* arr){
    for (int i = 0; i < arr->GetLength(); i++) {
        std::cout << arr->Get(i) << " ";
    };
    std::cout << std::endl;
    return;
};

void printmenu() {
    std::cout << "1. Set ArraySequence" << std::endl;
    std::cout << "2. Set LinkedList" << std::endl;
    std::cout << "3. Check Tests" << std::endl;
    std::cout << "4. Check sort functions time" << std::endl;
    std::cout << "5. exit" << std::endl;
    return;
};

#endif /* menu_functions_hpp */
