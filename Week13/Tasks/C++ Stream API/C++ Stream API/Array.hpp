#pragma once
#include "BaseCollection.hpp"
template <typename T>
class Array : public BaseCollection<T> {
private:
	T* data;
	int size;
public:
	Array(int size) :size(size) {
		data = new T[size];
	}
	explicit Array(const T* data, int size) :size(size) {
		if (size < 0)
		{
			throw std::invalid_argument("Invalid size");
		}
		if (data == nullptr)
		{
			throw std::invalid_argument("Paramater is null");
		}
		this->data = new T[size];
		for (int i = 0; i < size; i++)
		{
			this->data[i] = data[i];
		}
	}
	void setAt(int index, const T& obj) {
		if (index < 0 || index > size)
		{
			throw std::out_of_range("Out of bounds");
		}
		/*if (isValid(obj))
		{
			throw std::invalid_argument("Invalid object");
		}*/
		data[index] = obj;
	}
	const T& operator[](int index) const {
		if (index < 0 || index >= size)
		{
			throw std::out_of_range("Out of bounds");
		}
		return data[index];
	}
	T& operator[](int index) {
		if (index < 0 || index >= size)
		{
			throw std::out_of_range("Out of bounds");
		}
		return data[index];
	}
	Stream<T> stream() override {
		Stream<T> arr(size);
		for (int i = 0; i < size; i++)
		{
			arr[i] = data[i];
		}
		return arr;
	}
};