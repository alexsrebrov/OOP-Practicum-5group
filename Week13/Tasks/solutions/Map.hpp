#pragma once
#include "Pair.hpp"
#include "Vector.hpp"

template <typename K, typename V>
class Map : public Vector<Pair<K, V>>
{
public:
	Map(size_t size, Pair<K, V>* data);

	V findByKey(const K& key);
	const V& findByKey(const K& key) const;

	void addPair(const K& key, const V& value);
};

template<typename K, typename V>
Map<K, V>::Map(size_t size, Pair<K, V>* data) : Vector<Pair<K, V>>(size, data)
{
}

template<typename K, typename V>
inline V Map<K, V>::findByKey(const K& key)
{
	for (size_t i = 0; i < size; i++) 
	{
		if (data[i].key == key) {
			return data[i].value;
		}
	}

	throw std::runtime_error("Cant find element with this key");
}

template<typename K, typename V>
inline const V& Map<K, V>::findByKey(const K& key) const
{
	for (size_t i = 0; i < size; i++)
	{
		if (data[i].key == key) {
			return data[i].value;
		}
	}

	throw std::runtime_error("Cant find element with this key");
}

template<typename K, typename V>
inline void Map<K, V>::addPair(const K& key, const V& value)
{
	push_back({ key, value });
}
