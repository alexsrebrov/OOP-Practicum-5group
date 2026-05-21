#pragma once
#include <functional>
#include <algorithm>
#include <exception>
#include <stdexcept>
#include "Vector.hpp"
#include "Array.hpp"
#include "Map.hpp"
template <typename T>
class Stream {
private:
	T* data;
	int size;
	void copyFrom(const Stream& other);
	void moveFrom(Stream&& other) noexcept;
	void free();
public:
	Stream(int size) : size(size) {
		data = new T[size];
	}

	Stream(const Stream& other) {
		copyFrom(other);
	}

	Stream& operator=(const Stream& other)  {
		if (this != &other)
		{
			free();
			copyFrom(other);
		}
		return *this;
	}

	Stream(Stream&& other) noexcept {
		moveFrom(std::move(other));
	}

	Stream& operator=(Stream&& other) noexcept {
		if (this != &other)
		{
			free();
			moveFrom(std::move(other));
		}
		return *this;
	}

	~Stream() {
		free();
	}

	const T& operator[](int index)const {
		if (index < 0 || index > size)
		{
			throw std::out_of_range("Invalid index");
		}
		return data[index];
	}

	T& operator[](int index) {
		if (index < 0 || index > size)
		{
			throw std::out_of_range("Invalid index");
		}
		return data[index];
	}

	Stream& filter(std::function<bool(const T& obj)>predicate) {
		int countOfFiltered = 0;
		for (int i = 0; i < size; i++)
		{
			if ( predicate(data[i]))
			{
				countOfFiltered++;
			}
		}
		T* result = new T[countOfFiltered];
		for (int i = 0, j = 0; i < size, j < countOfFiltered; i++)
		{
			if (predicate(data[i]))
			{
				result[j++] = data[i];
			}
		}
		delete[] data;
		size = countOfFiltered;
		data = result;
		return *this;
	}

	Stream& sort(std::function<bool(const T& obj1, const T& obj2)> comparator) {
		std::sort(data, data + size, comparator);
		return *this;
	}
	
	Stream& limit(int n) {
		if (n < 0 || n > size)
		{
			throw std::out_of_range("index is out of bounds");
		}
		T* result = new T[n];
		for (int i = 0; i < n; i++)
		{
			result[i] = data[i];
		}
		size = n;
		delete[] data;
		data = result;
		return *this;
	}

	template< typename newType>
	Stream<newType> map(std::function<newType(const T& obj)> mapper) {
		Stream<newType> result(size);
		for (int i = 0; i < size; i++)
		{
			result[i] = mapper(data[i]);
		}
		return result;
	}

	Vector<T> toVector(){
		return Vector(data, size);
	}
	template <typename K>
	Map<T,K> toMap(std::function<K(const T& obj)> mapper) {
		Map<T, K> map;
		for (int i = 0; i < size; i++)
		{
			map.addPair(data[i], mapper(data[i]));
		}
		return map;
	}

	Array<T> toArray() {
		return Array(data, size);
	}
	
};

template<typename T>
inline void Stream<T>::copyFrom(const Stream& other)
{
	size = other.size;
	for (int i = 0; i < size; i++)
	{
		data[i] = other.data[i];
	}
}

template<typename T>
inline void Stream<T>::moveFrom(Stream&& other) noexcept
{
	size = other.size;
	data = other.data;
	other.data = nullptr;
	other.size = 0;
}


template<typename T>
inline void Stream<T>::free()
{
	delete[] data;
	data = nullptr;
	size = 0;
}

