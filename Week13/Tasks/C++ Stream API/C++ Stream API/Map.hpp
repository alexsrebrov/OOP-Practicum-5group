#pragma once
#include "BaseCollection.hpp"
#include "Pair.hpp"
template <typename K, typename V>

class Map : public BaseCollection<Pair<K, V>> {
private:
	std::vector<Pair<K, V>> map;
public:
	Map() = default;
	Map(K key, V val) {
		addPair(key, val);
	}

	const V& findByKey(const K& key) const {
		for (const auto& keys : map) {
			if (keys.getKey() == key)
			{
				return keys.getValue();
			}
		}
		throw std::invalid_argument("Not found");
	}


	const V& findByKey(const K& key) {
		for (auto& keys : map) {
			if (keys.getKey() == key)
			{
				return keys.getValue();
			}
		}
		throw std::invalid_argument("Not found");
	}

	void addPair(const K& key, const V& val) {
		map.push_back(Pair(key, val));
	}

	Stream<Pair<K, V>> stream() override {
		Stream<Pair<K, V>> m(map.size());
		for (int i = 0; i < map.size(); i++)
		{
			m[i] = map[i];
		}
		return m;
	}

};