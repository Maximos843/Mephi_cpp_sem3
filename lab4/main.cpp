#include <iostream>
#include "Menu_funtions.h"


int main(){
    int choice = 0;
    std::cout << "1. Menu" << std::endl;
    std::cout << "2. Tests Unorder Graph" << std::endl;
    std::cout << "3. Tests Order Graph" << std::endl;
    std::cin >> choice;
    while(choice < 0 || choice > 3){
        std::cout << "Please choose again" << std::endl;
        std::cin >> choice;
    }
    switch (choice){
    case 1:
        Menu();
        break;
    case 2:
        UnorderTests();
        break;
    case 3:
        OrderTests();
        break;
    default:
        break;
    }
    return 0;
}