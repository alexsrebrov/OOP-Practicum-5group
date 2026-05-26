#pragma once
#include <utility>

#include "Collection.hpp"
#include "Stream.hpp"
using namespace std;

template <typename T>
class Vector : public Collection<T> {
	static constexpr size_t INITIAL_CAPACITY = 8;

	void copyFrom(const Vector<T>& other);
	void free();
	void moveFrom(Vector<T>&& other);

	void resize(size_t newCapacity);

protected:
	T* data = nullptr;
	size_t capacity = 0;
	size_t size = 0;

public:
	Vector();
	Vector(size_t n);
	Vector(size_t n, const T& elem);
	Vector(size_t n, T* data);
	Vector(const Vector<T>& other);
	Vector(Vector<T>&& other) noexcept;
	Vector& operator=(const Vector<T>& other);
	Vector& operator=(Vector<T>&& other) noexcept;
	~Vector() override;

	void push_back(const T& elem);
	void push_back(T&& elem);

	void pop_back();

	void insert(size_t idx, const T& elem);
	void insert(size_t idx, T&& elem);

	void erase(size_t idx);

	T& operator[](size_t idx);
	const T& operator[](size_t idx) const;

	void shrink_to_fit();

	void clear();

	const T& front() const;
	T& front();

	const T& back() const;
	T& back();

	bool empty() const;

	size_t getSize() const;
	size_t getCapacity() const;

	Stream<T> stream() override;

	T* begin();
	T* end();

	const T* begin() const;
	const T* end() const;

	void limit(int n);
};

template<typename T>
void Vector<T>::copyFrom(const Vector<T>& other)
{
	size = other.size;
	capacity = other.capacity;

	data = new T[capacity];

	for (size_t i = 0; i < size; i++) {
		data[i] = other.data[i];
	}
}

template<typename T>
void Vector<T>::free()
{
	delete[] data;
	data = nullptr;
	size = 0;
	capacity = 0;
}

template<typename T>
void Vector<T>::moveFrom(Vector<T>&& other)
{
	size = other.size;
	capacity = other.capacity;

	data = other.data;

	other.data = nullptr;
	other.size = other.capacity = 0;
}

template<typename T>
void Vector<T>::resize(size_t newCapacity)
{

	T* newData = new T[newCapacity];

	for (size_t i = 0; i < size; i++) {
		newData[i] = std::move(data[i]);
	}

	delete[] data;

	capacity = newCapacity;
	data = newData;

}

template<typename T>
Vector<T>::Vector()
{
	size = 0;
	capacity = INITIAL_CAPACITY;
	data = new T[capacity];
}

template<typename T>
Vector<T>::Vector(size_t n)
{
	size = n;
	capacity = n;
	data = new T[capacity]{};
}

template<typename T>
Vector<T>::Vector(size_t n, const T& elem)
{
	size = capacity = n;
	data = new T[capacity]{};

	for (size_t i = 0; i < size; i++) {
		data[i] = elem;
	}
}

template<typename T>
inline Vector<T>::Vector(size_t n, T* data)
{
	this->capacity = this->size = n;
	this->data = new T[capacity]{};

	for (size_t i = 0; i < size; i++) {
		this->data[i] = data[i];
	}
}

template<typename T>
Vector<T>::Vector(const Vector<T>& other)
{
	copyFrom(other);
}

template<typename T>
Vector<T>::Vector(Vector<T>&& other) noexcept
{
	moveFrom(std::move(other));
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

template<typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

template<typename T>
Vector<T>::~Vector()
{
	free();
}

template<typename T>
void Vector<T>::push_back(const T& elem)
{
	if (size == capacity)
		resize(capacity * 2);

	data[size++] = elem;
}

template<typename T>
void Vector<T>::push_back(T&& elem)
{
	if (size == capacity)
		resize(capacity * 2);

	data[size++] = std::move(elem);
}

template<typename T>
void Vector<T>::pop_back()
{
	if (size == 0)
		return;

	size--;
}

template<typename T>
void Vector<T>::insert(size_t idx, const T& elem)
{
	if (idx > size)
		return;

	if (size == capacity)
		resize(capacity * 2);

	for (size_t i = size; i > idx; i--) {
		data[i] = std::move(data[i - 1]);
	}
	data[idx] = elem;
	size++;
}

template<typename T>
void Vector<T>::insert(size_t idx, T&& elem)
{
	if (idx > size)
		return;

	if (size == capacity)
		resize(capacity * 2);

	for (size_t i = size; i > idx; i--) {
		data[i] = std::move(data[i - 1]);
	}
	data[idx] = std::move(elem);
	size++;
}

template<typename T>
void Vector<T>::erase(size_t idx)
{
	if (idx >= size)
		return;

	for (size_t i = idx; i < size - 1; i++) {
		data[i] = std::move(data[i + 1]);
	}
	size--;
}

template<typename T>
T& Vector<T>::operator[](size_t idx)
{
	return data[idx];
}

template<typename T>
const T& Vector<T>::operator[](size_t idx) const
{
	return data[idx];
}

template<typename T>
void Vector<T>::shrink_to_fit()
{
	resize(size);
}

template<typename T>
void Vector<T>::clear()
{
	size = 0;
}

template<typename T>
const T& Vector<T>::front() const
{
	return data[0];
}

template<typename T>
T& Vector<T>::front()
{
	return data[0];
}

template<typename T>
const T& Vector<T>::back() const
{
	return data[size - 1];
}

template<typename T>
T& Vector<T>::back()
{
	return data[size - 1];
}

template<typename T>
bool Vector<T>::empty() const
{
	return size == 0;
}

template<typename T>
size_t Vector<T>::getSize() const
{
	return size;
}

template<typename T>
size_t Vector<T>::getCapacity() const
{
	return capacity;
}

template<typename T>
Stream<T> Vector<T>::stream() {
	return Stream<T>(data, size);
}

template<typename T>
T* Vector<T>::begin() {
	return data;
}

template<typename T>
T* Vector<T>::end() {
	return data + size;
}

template<typename T>
const T* Vector<T>::begin() const {
	return data;
}

template<typename T>
const T* Vector<T>::end() const {
	return data + size;
}

template<typename T>
void Vector<T>::limit(const int n) {
	if (n >= size) {
		return;
	}

	size = n;
}

