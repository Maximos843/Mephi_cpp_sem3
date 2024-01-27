#ifndef INTERFACE_H
#define INTERFACE_H

#include <string>
#include <limits>
#include <iostream>
#include <exception>
#include "Alphavit.h"
#include "KeyValue.h"
#include "tests.h"

const std::string MASTERPIECE = "";

template <class T>
void PrintArray(DynamicArray<T>* arr){
	std::cout << "Dynamic Array: " << std::endl;
	for (int i = 0; i < arr->GetLength(); i++)
		std::cout << arr->Get(i) << ' ';
	std::cout << std::endl;
}

void AlphabetSearcherPrint(AlphabetIndex* searcher) {
	ISortedSequence<KeyValue<std::string*, int>>* sequence = searcher->GetIndex();
	int number = 0;
	int page = 0;
	for (int i = 0; i < sequence->GetLength(); i++) {
		if (sequence->Get(i).key == page) {
			number++;
			std::cout << "	word "<< number << ": " << *(sequence->Get(i).value) << std::endl;
		}
		else {
			page++;
			std::cout << "Page: " << page << std::endl;
			number = 0;
			i--;
		}
	}
}

void PrintMenu(){
	std::cout << "1. Input your text" << std::endl;
    std::cout << "2. Check Tests" << std::endl;
    std::cout << "3. Exit" << std::endl;
}


#endif