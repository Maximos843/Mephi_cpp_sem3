#ifndef Alphavit_h
#define Alphavit_h

#include <string>
#include <stdexcept>
#include "ISortedSequence.h"
#include "KeyValue.h"
#include "IndexError.h"


class AlphabetIndex {
private:
	std::string text = "";
	int wordcapacity = 1;
	ISortedSequence<KeyValue<std::string*, int>>* index;
	int pages = 0;

public:
	AlphabetIndex() : index(new ISortedSequence<KeyValue<std::string*, int>>()){};

	AlphabetIndex(int count) : wordcapacity(count), index(new ISortedSequence<KeyValue<std::string*, int>>()){};

	AlphabetIndex(std::string text, int count) {
		std::string tmp(text);
		this->text = text;
		this->wordcapacity = count;
		this->index = Decompose(tmp, wordcapacity);
	};

	int PageCapacity(int capacity, int number) {
		if (number == 1){
			return capacity / 2;
		}
		if (number % 10 == 0){
			return capacity * 3 / 4;
		}
		return capacity;
	}

	ISortedSequence<KeyValue<std::string*, int>>* Decompose(std::string str, int capacity) {
		str.append(" ");
		while (true) {
			int pos = str.find("  ");
			if (pos == -1){
				break;
			}
			str.replace(pos, 2, " ");
		}
		if (str[0] == ' ')
			str.erase(0, 1);
		ISortedSequence<KeyValue<std::string*, int>>* res = new ISortedSequence<KeyValue<std::string*, int>>();
		int counter = 0;
		int page = 1;
		while (true) {
			int pos = str.find(" ");
			if (pos == -1) {
				this->pages = page;
				break;
			}
			std::string* tmp_str = new std::string(str.substr(0, pos));
			++counter;
			while (true){
				int this_page_capacity = PageCapacity(capacity, page);
				if (counter <= this_page_capacity){
					KeyValue<std::string*, int> tmp = { tmp_str, page };
					res->Add(tmp);
					str.erase(0, pos + 1);
					break;
				}
				else{
					counter = 1;
					++page;
					continue;
				}
			}
		}
		return res;
	}

	void SetText(std::string text) {
		this->text = text;
		std::string tmp(text);
		index = Decompose(tmp, wordcapacity);
	}

	void SetCapacity(int capacity) {
		if (capacity < 0){
			throw std::length_error(SIZE_LOWER_ZERO);
		}
		if (capacity == 0){
			throw std::length_error(SIZE_ZERO);
		}
		wordcapacity = capacity;
		if (text != "") {
			std::string tmp(text);
			index = Decompose(tmp, wordcapacity);
		}
	}

	int GetLength() {
		return index->GetLength();
	}

	int GetNumberOfPages() {
		return pages;
	}

	int GetCapacity() {
		return wordcapacity;
	}

	std::string GetText() {
		return text;
	}

	ISortedSequence<KeyValue<std::string*, int>>* GetIndex() {
		return index;
	}

	KeyValue<std::string*, int> FindByParam(int page, int param){
		if (param < -1 || param > 1){
			throw std::logic_error(INVALID_PARAM);
		}
		std::string* str = new std::string("");
		KeyValue<std::string*, int> tmp = {str, page};
		try{
			return index->Find([](KeyValue<std::string*, int> a, KeyValue<std::string*, int> b) {
				if (a.key < b.key)
					return -1;
				if (a.key > b.key)
					return 1;
				else
					return 0;
				}, tmp, param);
		}
		catch (const std::exception& e){
			throw std::logic_error(e.what());
		}
	}

	ISortedSequence<KeyValue<std::string*, int>>* FindElementsByParam(int page, int param) {
		if (param < -1 || param > 1){
			throw std::logic_error(INVALID_PARAM);
		}
		if (param == -1) {
			if (page <= 1){
				throw std::logic_error(EMPTY_ELEMENT);
			}
			int left = 0;
			int right = 0;
			int count = std::min(this->pages, page);
			if (count == this->pages){
				count++;
			}
			for (int i = 1; i < count; i++)
				right += PageCapacity(this->wordcapacity, i);
			return index->GetSubSequence(left, right - 1);
		}
		else if (param == 1) {
			if (page >= this->pages){
				throw std::logic_error(EMPTY_ELEMENT);
			}
			int right = this->GetLength() - 1;
			int left = 0;
			for (int i = 1; i < page+1; i++)
				left += PageCapacity(this->wordcapacity, i);
			return this->index->GetSubSequence(left, right);
		}
		else {
			if (page > this->pages || page < 1){
				throw std::logic_error(EMPTY_ELEMENT);
			}
			int left = 0;
			int right = 0;
			for (int i = 1; i < page; i++)
				left += PageCapacity(this->wordcapacity, i);
			if (page  ==  this->pages)
				right = this->GetLength();
			else
				right = left + PageCapacity(this->wordcapacity, page);
			return this->index->GetSubSequence(left, right - 1);
		}
	}
};


#endif