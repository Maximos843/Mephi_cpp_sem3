#ifndef TESTS_H
#define TESTS_H

#include <iostream>

#include <string>
#include "AVLTree.h"
#include "DynamicArray.h"
#include "ISortedSequence.h"
#include "KeyValue.h"
#include "Alphavit.h"
#include "menu_functions.h"

const std::string TEXT = "Always write the code as if it will be accompanied by a violent psychopath who knows where you live.";


template <class T>
int comp(T a, T b){
	if (a < b)
		return -1;
	if (a > b)
		return 1;
	return 0;
}

template <class T>
void CompareSeq(DynamicArray<T>* arr1, DynamicArray<T>* arr2){
	for (int i = 0; i < arr1->GetLength(); ++i){
		if (arr1->Get(i) != arr2->Get(i)){
			std::cout << "	ERROR!!!" << std::endl;
		}
	}
	std::cout << "	Correct" << std::endl;
}

void PrintInfoTree(AVLTree<int>* avl, int all_out){
	if (all_out){
		std::cout << "Tree info" << std::endl;
		std::cout << "Root is "  << avl->GetRoot()->GetData() << std::endl;
		std::cout << "Length is "  << avl->GetLength() << std::endl;
		std::cout << "Tree in Dynamic Array " << std::endl;
		avl->PrintTree(avl->GetRoot());
		std::cout << std::endl;
		std::cout << "Min is " << avl->FindMin(avl->GetRoot())->GetData() << std::endl;
		std::cout << "Max is " << avl->FindMax(avl->GetRoot())->GetData() << std::endl;
		std::cout << "-----------------------------------------------" << std::endl;
	}
	else{
		std::cout << "Tree in Dynamic Array " << std::endl;
		avl->PrintTree(avl->GetRoot());
		std::cout << std::endl;
		std::cout << "-----------------------------------------------" << std::endl;
	}
}

void FindElementTree(AVLTree<int>* avl, int x, int param){
	std::string text;
	if (param == -1){
		text = "First element lower than x - ";
	}
	else if (param == 1){
		text = "First element bigger than x - ";
	}
	else{
		text = "Element x equals - ";
	}
	try{
		std::cout << text << avl->Find(avl->GetRoot(), comp<int>, x, param) << std::endl;
	}
	catch(const std::exception& e){
		std::cout << e.what() << '\n';
	}
	std::cout << "-----------------------------------------------" << std::endl;
}

void AVLTreeTests(){
	std::cout << "AVLTree Tests" << std::endl;

	int arr[20] = {1, 10, 19, 3, 5, 2, 78, 0, 2, 34, 54, 6, 12, 13, 14, 15, 16, 17, 18, 20};
	std::cout << "Size Tests" << std::endl;
	std::cout << "    Negative size:" << std::endl;
	try{
		AVLTree<int>* avl = new AVLTree<int>(arr, -2);
	}
	catch(const std::exception& e){
		std::cout << "    " <<  e.what() << '\n';
	}
	std::cout << "    Zero size:" << std::endl;
	try{
		AVLTree<int>* avl = new AVLTree<int>(arr, 0);
	}
	catch(const std::exception& e){
		std::cout << "    " <<  e.what() << '\n';
	}
	std::cout << "    Size 20:" << std::endl;
	AVLTree<int>* avl = new AVLTree<int>(arr, 20);
	PrintInfoTree(avl, 1);

	std::cout << std::endl << "Add/Remove Tests" << std::endl;
	std::cout << "Add 1:" << std::endl;
	avl->Add(1);
	int corr1[21] = {0, 1, 1, 2, 2, 3, 5, 6, 10, 12, 13, 14, 15, 16, 17, 18, 19, 20, 34, 54, 78};
	DynamicArray<int> correct1(corr1, 21);
	CompareSeq(avl->TreeToDynamicArray(), &correct1);
	std::cout << "Add 7:" << std::endl;
	avl->Add(7);
	int corr2[22] = {0, 1, 1, 2, 2, 3, 5, 6, 7, 10, 12, 13, 14, 15, 16, 17, 18, 19, 20, 34, 54, 78};
	DynamicArray<int> correct2(corr2, 22);
	CompareSeq(avl->TreeToDynamicArray(), &correct2);
	std::cout << "Remove 7:" << std::endl;
	avl->Remove(7);
	int corr3[21] = {0, 1, 1, 2, 2, 3, 5, 6, 10, 12, 13, 14, 15, 16, 17, 18, 19, 20, 34, 54, 78};
	DynamicArray<int> correct3(corr3, 21);
	CompareSeq(avl->TreeToDynamicArray(), &correct3);
	std::cout << "Remove 1:" << std::endl;
	avl->Remove(1);
	int corr4[20] = {0, 1, 2, 2, 3, 5, 6, 10, 12, 13, 14, 15, 16, 17, 18, 19, 20, 34, 54, 78};
	DynamicArray<int> correct4(corr4, 20);
	CompareSeq(avl->TreeToDynamicArray(), &correct4);

	std::cout << std::endl << "Find Tests" << std::endl;
	std::cout << "X = 1"<< std::endl;
	FindElementTree(avl, 1, -1);
	std::cout << "X = 3"<< std::endl;
	FindElementTree(avl, 3, 1);
	std::cout << "X = 20"<< std::endl;
	FindElementTree(avl, 20, 0);
	std::cout << "X = 7"<< std::endl;
	FindElementTree(avl, 7, 0);

	std::cout << std::endl << "AVL to DynamicArray and Check IsEqual" << std::endl;
	PrintInfoTree(avl, 0);
	DynamicArray<int>* dynamic = avl->TreeToDynamicArray();
	PrintArray(dynamic);
	int arr_true[20] = {0, 1, 2, 2, 3, 5, 6, 10, 12, 13, 14, 15, 16, 17, 18, 19, 20, 34, 54, 78};
	if (dynamic->IsEqual(arr_true, 20)){
		std::cout << "	Correct" << std::endl;
	}
	else{
		std::cout << "	ERROR!!!" << std::endl;
	}
}


void ComprasionsKeyValue(int x, int y) {
	KeyValue<int, int> pair1 = {2, x};
	KeyValue<int, int> pair2 = {2, y};
	if (pair1 < pair2){
		std::cout << "("<< pair1.key << "; "<< pair1.value << ") < " << "(" << pair2.key << "; " << pair2.value << ")" << std::endl;
	}
	else{
		std::cout << "(" << pair1.key << "; " << pair1.value << ") >= " << "(" << pair2.key << "; " << pair2.value << ")" << std::endl;
	}
}

void KeyValueTests() {
	std::cout << std::endl << "KeyValue Structure Comprasion Tests: " << std::endl;
	std::cout << "Bigger Tests: " << std::endl;
	ComprasionsKeyValue(2, 3);
	ComprasionsKeyValue(5, 2);
	std::cout << "Lower Tests: " << std::endl;
	ComprasionsKeyValue(-4, -6);
	ComprasionsKeyValue(-23, -22);
}


void AlphabetSearcherInfo(AlphabetIndex* searcher) {
	std::cout << "Capacity: " << searcher->GetCapacity() << std::endl;
	std::cout << "Length: " << searcher->GetLength() << std::endl;
	std::cout << "Text: " << std::endl << searcher->GetText() << std::endl;
	AlphabetSearcherPrint(searcher);
	std::cout << "-----------------------------------------------" << std::endl;
}

void AlphabetSearcherFind(AlphabetIndex* searcher, int page, int param) {
	try{
		std::cout << "	Find elem on page ";
		if (param == 0){
			std::cout << "=";
		}
		else if (param == 1){
			std::cout << ">";
		}
		else{
			std::cout << "<";
		}
		std::cout << " " << page << std::endl;
		KeyValue<std::string*, int> sequence = searcher->FindByParam(page, param);
		std::cout << "First elem: page " << sequence.key << ", word " << *(sequence.value) << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << '\n';
	}
	std::cout << "-----------------------------------------------" << std::endl;
}

/*void AlphabetSearcherFindElements(AlphabetIndex* searcher, int page, int param) {
	try{
		std::cout << "	Find elements on page ";
		if (param == 0){
			std::cout << "=";
		}
		else if(param == 1){
			std::cout << ">";
		}
		else{
			std::cout << "<";
		}
		std::cout << " " << page << std::endl;
		ISortedSequence<KeyValue<std::string*, int>>* sequence = searcher->FindElementsByParam(page, param);
		for (int i = 0; i < sequence->GetLength(); i++) {
			std::cout << "(" << sequence->Get(i).key << " ; " << *(sequence->Get(i).value) << ") ";
		}
		std::cout << std::endl;
	}
	catch (std::exception& e){
		std::cout << e.what() << '\n';
	}
	std::cout << "-----------------------------------------------" << std::endl;
}*/

void AlphabetSearcherTests() {
	std::cout << "Alphabet Searcher Tests: "<< std::endl;
	AlphabetIndex* searcher = new AlphabetIndex();
	searcher->SetCapacity(6);
	searcher->SetText(TEXT);
	AlphabetSearcherInfo(searcher);

	std::cout << std::endl << "Invalid param: " << std::endl;
	AlphabetSearcherFind(searcher, 1, -2);

	std::cout << std::endl << "Invalid page: " << std::endl;
	AlphabetSearcherFind(searcher, 5, 1);

	std::cout << std::endl << "Check Find functions: " << std::endl;
	AlphabetSearcherFind(searcher, 2, 1);
	AlphabetSearcherFind(searcher, 1, 1);
	AlphabetSearcherFind(searcher, 3, -1);
	//AlphabetSearcherFindElements(searcher, 2, 1);

}


#endif //tests_H
