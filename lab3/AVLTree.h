#ifndef AVLTree_h
#define AVLTree_h

#include <iostream>
#include "DynamicArray.h"
#include <stdexcept>
#include "KeyValue.h"


const std::string SIZE_LOWER_ZERO = "Size < 0";
const std::string SIZE_ZERO = "Size = 0";
const std::string INVALID_PARAM = "Invalid param";
const std::string INDEX_OUT_OF_RANGE = "Index out of range";
const std::string EMPTY_ELEMENT = "Index out of range";


template <typename T>
class Node {
private:
	T data;

public:
	Node<T>* ptr_left = nullptr;
	Node<T>* ptr_right = nullptr;
	int height = 1;

	Node<T>() : data(0) {
		ptr_left = nullptr;
		ptr_right = nullptr;
		height = 1;
	};

	Node<T>(T item) : data(item){
		ptr_left = nullptr;
		ptr_right = nullptr;
		height = 1;
	};

	int GetHeight() {
		if (this == nullptr){
			return 0;
		}
		return this->height;
	}

	T GetData() {
		return data;
	}

	void SetData(T item) {
		this->data = item;
		return;
	}

	int DiffHeight(){
		return this->ptr_right->GetHeight() - this->ptr_left->GetHeight();
	}

	void SetHeight(){
		int right_height = this->ptr_right->GetHeight();
		int left_height = this->ptr_left->GetHeight();
		if (right_height > left_height){
			this->height = left_height + 1;
		}
		else{
			this->height = right_height + 1;
		}
	}
};

template <typename T>
class AVLTree {
private:
	Node<T>* root;
	int length;

public:

	AVLTree() : root(nullptr), length(0) {};

	AVLTree(T* item, int len) : AVLTree(){
		if (len == 0){
			throw std::length_error(SIZE_ZERO);
		}
		if (len < 0){
			throw std::length_error(SIZE_LOWER_ZERO);
		}
		this->root = new Node<T>(*(item));
		this->length = 1;
		for (int i = 1; i < len; ++i) {
			this->Add(*(item + i));
		}
	};

	AVLTree(DynamicArray<T>& arr, int left, int right) : AVLTree(){
		if ((left > right) || (left < 0) || (right < 0) || (right >= arr.GetSize())){
			throw INDEX_OUT_OF_RANGE;
			//throw IndexError(Out_of_range);
        }
		this->root = new Node<T>(arr.Get(left));
		this->length = 1;
		for (int i = left + 1; i < right + 1; ++i) {
			this->Add(arr.Get(i));
		}
	};

	AVLTree(DynamicArray<T>& array) : AVLTree(array, 0, array.GetSize() - 1) {};

	int GetLength(){
		return length;
	}

	T GetData(Node<T>* ptr){
		return ptr->GetData();
	}

	void* GetLeft(Node<T>* ptr){
		return (void *) ptr->ptr_leht;
	}

	void* GetRight(Node<T>* ptr){
		return (void *) ptr->ptr_right;
	}

	Node<T>* GetRoot(){
		return this->root;
	}

	Node<T>* RightRotate(Node<T>* ptr){
		Node<T>* left_ptr = ptr->ptr_left;
		ptr->ptr_left = left_ptr->ptr_right;
		left_ptr->ptr_right = ptr;
		ptr->SetHeight();
		left_ptr->SetHeight();
		return left_ptr;
	}

	Node<T>* LeftRotate(Node<T>* ptr){
		Node<T>* right_ptr = ptr->ptr_right;
		ptr->ptr_right = right_ptr->ptr_left;
		right_ptr->ptr_left = ptr;
		ptr->SetHeight();
		right_ptr->SetHeight();
		return right_ptr;
	}

	Node<T>* Balance(Node<T>* ptr){
		ptr->SetHeight();
		if (ptr->DiffHeight() == 2){
			if (ptr->ptr_right->DiffHeight() < 0)
				ptr->ptr_right = RightRotate(ptr->ptr_right);
			return LeftRotate(ptr);
		}
		if (ptr->DiffHeight() == -2){
			if (ptr->ptr_left->DiffHeight() > 0)
				ptr->ptr_left = LeftRotate(ptr->ptr_left);
			return RightRotate(ptr);
		}
		return ptr;
	}

	Node<T>* Add(T data){
		root = Add(this->root, data);
		++length;
		return this->root;
	}

	Node<T>* Add(Node<T>* ptr, T data){
		if (ptr == nullptr){
			return new Node<T>(data);
		}
		if (data < GetData(ptr)){
			ptr->ptr_left = Add(ptr->ptr_left, data);
		}
		else{
			ptr->ptr_right = Add(ptr->ptr_right, data);
		}
		return Balance(ptr);
	}

	Node<T>* FindMin(Node<T>* ptr){
		if (ptr->ptr_left){
			return FindMin(ptr->ptr_left);
		}
		return ptr;
	}

	Node<T>* FindMax(Node<T>* ptr){
		if (ptr->ptr_right){
			return FindMax(ptr->ptr_right);
		}
		return ptr;
	}

	Node<T>* RemoveMin(Node<T>* ptr){
		if (ptr->ptr_left == nullptr){
			return ptr->ptr_right;
		}
		ptr->ptr_left = RemoveMin(ptr->ptr_left);
		return Balance(ptr);
	}


	Node<T>* Remove(Node<T>* ptr, T data){
		if (ptr == nullptr){
			return nullptr;
		}
		if (data < ptr->GetData()){
			ptr->ptr_left = Remove(ptr->ptr_left, data);
		}
		else if (data > ptr->GetData()){
			ptr->ptr_right = Remove(ptr->ptr_right, data);
		}
		else{
			Node<T>* left_ptr = ptr->ptr_left;
			Node<T>* right_ptr = ptr->ptr_right;
			delete ptr;
			this->length--;
			if (right_ptr == nullptr){
				return left_ptr;
			}
			Node<T>* min = FindMin(right_ptr);
			min->ptr_right = RemoveMin(right_ptr);
			min->ptr_left = left_ptr;
			return Balance(min);
		}
		return Balance(ptr);
	}

	Node<T>* Remove(T data){
		root = Remove(root, data);
		return root;
	}

	bool Find(T item) const{
		Node<T>* node = this->root;
		while (node){
			if (node->GetData() == item){
				return true;
			}
			if (node->GetData() > item){
				node = node->ptr_left;
			}
			else{
				node = node->ptr_right;
			}
		}
		return false;
	}


	/*T Find(int (*func)(T, T), T a, int param) const // åñëè ýëåìåíòà íåò âûáðàñûâàåò èñêëþ÷åíèå
	{
		if (param < -1 || param > 1) throw std::logic_error(AVL_INCORRECT_PARAM_MESSAGE);
		Node<T>* node = this->root;
		try
		{
			return Find(node, func, a, param);
		}
		catch (const std::exception& e)
		{
			throw std::logic_error(e.what());
		}
	}*/

	T Find(Node<T>* node, int (*func)(T, T), T a, int param) const{
		if (param < -1 || param > 1){
			throw std::logic_error(INVALID_PARAM);
		}
		if (node != nullptr){
			try{
				if (func(node->GetData(), a) == param){
				return node->GetData();
				}
				if (param < 0){
					return Find(node->ptr_left, func, a, param);
				}
				else if (param > 0){
					return Find(node->ptr_right, func, a, param);
				}
				else{
					if (func(node->GetData(), a) > 0){
						return Find(node->ptr_left, func, a, param);
					}
					else{
						return Find(node->ptr_right, func, a, param);
					}
				}
			}
			catch(const std::exception& e){
				throw std::logic_error(e.what());
			}
		}
		throw std::logic_error(EMPTY_ELEMENT);
	}


	void DeleteTree(Node<T>* ptr) {
		if (ptr == nullptr){
			return;
		}
		deleteTree(ptr->ptr_left);
		deleteTree(ptr->ptr_right);
		delete ptr;
	}

	void TreeToDynamicArray(DynamicArray<T>* ans, Node<T>* ptr) {
		if (ptr == nullptr){
			return;
		}
		if (ptr->ptr_left == nullptr) {
			ans->Append(ptr->GetData());
			TreeToDynamicArray(ans, ptr->ptr_right);
			return;
		}
		else {
			TreeToDynamicArray(ans, ptr->ptr_left);
			ans->Append(ptr->GetData());
			TreeToDynamicArray(ans, ptr->ptr_right);
			return;
		}
	}

	DynamicArray<T>* TreeToDynamicArray() {
		DynamicArray<T>* ans = new DynamicArray<T>(this->length);
		TreeToDynamicArray(ans, this->root);
		return ans;
	}

	void PrintTree(Node<T>* ptr){
		if (ptr == nullptr){
			return;
		}
		if (ptr->ptr_left == nullptr) {
			std::cout << ptr->GetData() << " ";
			PrintTree(ptr->ptr_right);
			return;
		}
		else {
			PrintTree(ptr->ptr_left);
			std::cout << ptr->GetData() << " ";
			PrintTree(ptr->ptr_right);
			return;
		}
	}
};

template <typename T>
bool operator<(const T& p1,const T& p2) {
	if (typeid(T).name() == typeid(KeyValue<std::string*, int>).name())
		return p1.key < p2.key;
	else
		return p1 < p2;
}
template <typename T>
bool operator>(const T& p1, const T& p2) {
	if (typeid(T).name() == typeid(KeyValue<std::string*, int>).name())
		return p1.key > p2.key;
	else
		return p1 > p2;
}

template <typename T>
bool operator==(const T& p1, const T& p2) {
	if (typeid(T).name() == typeid(KeyValue<std::string*, int>).name())
		return (p1.key == p2.key) && (p1.value == p2.value);
	else
		return p1 == p2;
}

#endif