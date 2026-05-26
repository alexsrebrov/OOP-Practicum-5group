#pragma once

template <typename K, typename V>
struct Pair
{
	K key;
	V value;

	Pair() = default;
	Pair(K key, V value);
};

template<typename K, typename V>
inline Pair<K, V>::Pair(K key, V value) : key(key), value(value)
{}
