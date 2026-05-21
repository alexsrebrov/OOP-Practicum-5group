#pragma once
#include "BaseCollection.hpp"
#include <vector>
template <typename T>
class Vector : public BaseCollection<T>{
private:
	
	std::vector<T> vector;
	int capacity;
public:
	Vector(int capacity) :capacity(capacity) {
		if (capacity < 0)
		{
			throw std::invalid_argument("Capacity should be a positive number");
		}
		vector.reserve(capacity);
	}
	Vector(const T* data, int size) : capacity(size) {
		if (size < 0)
		{
			throw std::invalid_argument("Invalid size");
		}
		if (data == nullptr)
		{
			throw std::invalid_argument("Paramater is null");
		}
		for (size_t i = 0; i < size; i++)
		{
			vector.push_back(data[i]);
		}
	}

	Vector(const Vector<T>& other) {
		capacity = other.capacity;
		vector = other.vector;
	}

	void addElement(const T& obj) {
		vector.push_back(obj);
	}

	void removeAt(int index) {
		if (index < 0 || index >= vector.size())
		{
			throw std::invalid_argument("Capacity should be a positive number");
		}
		vector.erase(vector.begin() + index);
	}

	const T& operator[](int index) const {
		if (index < 0 || index >= capacity)
		{
			throw std::invalid_argument("Capacity should be a positive number");
		}
		return vector[index];
	}

	T& operator[](int index) {
		if (index < 0 || index >= capacity)
		{
			throw std::invalid_argument("Capacity should be a positive number");
		}
		return vector[index];
	}
	Stream<T> stream() override {
		Stream<T> vec(static_cast<int>(vector.size()));
		for (size_t i = 0; i < vector.size(); i++)
		{
			vec[i] = vector[i];
		}
		return vec;
	}
	
};