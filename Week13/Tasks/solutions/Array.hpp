#pragma once
#include "Collection.hpp"
#include <iostream>

template <typename T>
class Array : public Collection<T> {
private:
	T* data = nullptr;
	size_t size = 0;

public:
	Array(size_t size);
	Array(size_t size, T* data);

	void setAt(size_t idx, const T& element);

	T operator[](size_t idx);
	const T operator[](size_t idx) const;

	friend std::ostream& operator<<(std::ostream& os, const Array<T>& arr);

	T* begin();
	T* end();

	const T* begin() const;
	const T* end() const;

	Stream<T> stream() override;
};

template<typename T>
inline Array<T>::Array(size_t size)
{
	this->size = size;
	this->data = new T[size]{};
}

template<typename T>
inline Array<T>::Array(size_t size, T* data)
{
	this->size = size;
	this->data = new T[size]{};

	for (size_t i = 0; i < size; i++) {
		this->data[i] = data[i];
	}
}

template<typename T>
void Array<T>::setAt(size_t idx, const T& element)
{
	if (idx >= size) {
		throw std::invalid_argument("Index out of bounds");
	}
	
	data[idx] = element;
}

template<typename T>
T Array<T>::operator[](size_t idx)
{
	if (idx >= size) {
		throw std::invalid_argument("Index out of bounds");
	}
	return data[idx];
}

template<typename T>
const T Array<T>::operator[](size_t idx) const
{
	if (idx >= size) {
		throw std::invalid_argument("Index out of bounds");
	}
	return data[idx];
}

template<typename T>
T* Array<T>::begin()
{
	return data;
}

template<typename T>
T* Array<T>::end()
{
	return data;
}

template<typename T>
const T* Array<T>::begin() const
{
	return data + size;
}

template<typename T>
const T* Array<T>::end() const
{
	return data + size;
}

template<typename T>
inline Stream<T> Array<T>::stream()
{
	return Stream<T>(data, size);
}


template<typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& arr)
{
	for (size_t i = 0; i < size; i++) {
		os << arr[i] << " ";
	}

	return os;
}

