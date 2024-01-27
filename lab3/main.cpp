#include <iostream>
#include "tests.h"
#include "menu_functions.h"
#include <string>


int main(){
	int n;
	PrintMenu();
	std::cin >> n;
	switch (n){
		case 1:
		{
			int capacity;
			int choose_option;
			std::string text;
			std::cout << "Enter text: " << std::endl;
			do
			{
				std::getline(std::cin, text);
			} while (text.length() ==  0);
			std::cout << "Enter capacity:" << std::endl;
			std::cin >> capacity;
			AlphabetIndex* searcher = new AlphabetIndex(text, capacity);
			while(choose_option != 5){
				std::cout << "Options:\n1. Print All Info\n2. Find Element By Param\n3. Change Capacity\n4. Change Text\n5. Exit\n";
				std::cin >> choose_option;
				switch (choose_option){
					case 1:
						AlphabetSearcherPrint(searcher);
						break;
					case 2:
						int param;
						int page;
						std::cout << "Input page number:\n";
						std::cin >> page;
						std::cout << "Input param:\n";
						std::cin >> param;
						AlphabetSearcherFind(searcher, page, param);
						break;
					case 3:
						std::cout << "Enter new capacity:\n";
						std::cin >> capacity;
						searcher->SetCapacity(capacity);
						break;
					case 4:
						std::cout << "Enter new text:\n";
						std::getline(std::cin, text);
						searcher->SetText(text);
						break;
					default:
						break;
				}
			}
			break;
		}
		case 2:
		{
			int test_choice;
			std::cout << "Choose Tests to check:\n1. AVLTree Tests\n2. KeyValue Compare Tests\n3. AlphabetSearcher Tests\n4. All Tests" << std::endl;
			std::cin >> test_choice;
			switch (test_choice){
				case 1:
					AVLTreeTests();
					break;
				case 2:
					KeyValueTests();
					break;
				case 3:
					AlphabetSearcherTests();
					break;
				case 4:
					AVLTreeTests();
					KeyValueTests();
					AlphabetSearcherTests();
					break;
				default:
					break;
				}
				break;
		}
		case 3:
			break;
		default:
			break;
	}
    return 0;
}