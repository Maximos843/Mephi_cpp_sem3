#ifndef ISortedSequence_h
#define ISortedSequence_h

#include <string>
#include "AVLTree.h"


template <typename T>
class ISortedSequence{
private:
	AVLTree<T>* ptr;

public:
	ISortedSequence<T>() : ptr(new AVLTree<T>()) {};

	ISortedSequence<T>(AVLTree<T>* tree) : ptr(tree) {};

	AVLTree<T>* GetTree() {
		return ptr;
	}

	int GetLength() {
		return ptr->GetLength();
	}

	bool IsEmpty() {
		if (this->ptr == nullptr)
			return true;
		else
			return false;
	}

	T GetFirst() {
		return ptr->FindMin()->GetData();
	}

	T GetLast() {
		return ptr->FindMax()->GetData();
	}

	void Add(T item) {
		ptr->Add(item);
		return;
	}

	void Remove(T item) {
		ptr->Remove(item);
		return;
	}

	T Get(int index){
		if (index < 0 || index >= this->ptr->GetLength()){
            throw std::out_of_range(INDEX_OUT_OF_RANGE);
        }
		return ptr->TreeToDynamicArray()->Get(index);
	}

	int IndexOfElement(T item) {
		if (!(ptr->Find(item))){
            return -1;
        }
		return ptr->TreeToDynamicArray()->IndexOfElement(item);
	}

	bool Find(T data) {
		return ptr->Find();
	}

	T Find(int (*func)(T, T), T a, int param) {
		if (param < -1 || param > 1){
			throw std::logic_error(INVALID_PARAM);
		}
		try{
			return ptr->Find(ptr->GetRoot(), func, a, param);
		}
		catch (const std::exception&){
			throw std::logic_error(EMPTY_ELEMENT);
		}
	}

    ISortedSequence<T>* GetSubSequence(int left, int right) {
		if ((left > right) || (left < 0) || (right < 0) || (right >= ptr->GetLength())){
			throw std::out_of_range(INDEX_OUT_OF_RANGE);
        }
		DynamicArray<T>* tmp = ptr->TreeToDynamicArray();
		AVLTree<T>* avl_new = new AVLTree<T>(*(tmp), left, right);
		return new ISortedSequence<T>(avl_new);
	}

	ISortedSequence<T>* GetSubSequence(int (*func)(T, T), T a, int param) {
		ISortedSequence<T>* tmp = this->GetSubSequence(0, this->GetLength() - 1);
		ISortedSequence<T>* res = new ISortedSequence();
		while (true){
			T item = tmp->Find(func, a, param);
			tmp->Remove(item);
			res->Add(item);
        }
		return res;
	}
};


#endif