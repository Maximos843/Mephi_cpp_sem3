#ifndef KeyValue_h
#define KeyValue_h

#include <iostream>
#include <fstream>

template <typename V, typename K>
struct KeyValue{
	V value = 0;
	K key = 0;

	K GetKey() {
		return key;
	}

	bool operator>(KeyValuePair<V, K>& p2){
		return this->key > p2.key;
	}

	bool operator<(KeyValuePair<V,K>& p2){
		return this->key < p2.key;
	}
};

template <typename V, typename K>
std::ostream& operator<<(std::ostream& os, KeyValue<V,K>& p2){
	os << p2.value;
	return os;
}

#endif