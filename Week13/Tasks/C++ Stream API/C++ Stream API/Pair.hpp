#pragma once
#include "BaseCollection.hpp"
template <typename K, typename V>
class Pair  {
protected: 
	K key;
	V value;
public:
	Pair() = default;
	Pair(K key, V val):key(key), value(val){}
	virtual ~Pair() = default;
	const V& getValue() const { return value; }
	const K& getKey() const { return key; }
};