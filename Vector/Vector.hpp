#pragma once
#include <ostream>
#include <istream>
#include <iostream>
#include <iomanip>
#include "Exception.hpp"
#define SETW 5
template <typename T1>
class Vector;
template <typename T>
std::ostream& operator<< (std::ostream& stream, const Vector<T>& _vector);
template <typename T>
std::istream& operator>> (std::istream& stream, const Vector<T>& _vector);
template <typename T>
class Vector {
private:
	T* _array;
	size_t count;
public:
	Vector() {
		_array = nullptr;
		count = 0;
	}
	Vector(size_t count) {
		_array = new T[count];
		this->count = count;
	}
	Vector(const Vector<T>& _vector);
	size_t getSize() {
		return count;
	}
	T& at(size_t index) {
		if (index >= count)
			throw OutOfRangeException(__FILE__, __FUNCTION__, __LINE__);
		return _array[index];
	}
	~Vector() {
		delete[] _array;
		count = 0;
	}
	void push_back(const T& element);
	T& getBack() {
		return _array[count - 1];
	}
	T& getFront() {
		return _array[0];
	}
	const bool operator==(const Vector<T>& _vector) const;
	void resize(size_t size);
	const bool operator!=(const Vector<T>& _vector) const;
	Vector<T>& operator-= (const Vector<T>& _vector);
	Vector<T>& operator=(const Vector<T>& _vector);
	const bool operator<= (const Vector<T>& _vector) const;
	const bool operator>= (const Vector<T>& _vector) const;
	const bool operator< (const Vector<T>& _vector) const;
	const bool operator> (const Vector<T>& _vector) const;
	const Vector<T> operator+ (const Vector<T>& _vector) const;
	const Vector<T> operator* (const T& scalar) const;
	const Vector<T> operator- (const Vector<T>& _vecctor) const;
	const Vector<T> operator/ (const T& scalar) const;
	Vector<T>& operator*= (const T& scalar);
	Vector<T>& operator+= (const Vector<T>& _vector);
	Vector<T>& operator/= (const T& scalar);
	const Vector<T>& operator++();
	const Vector<T> operator++(int);
	const T operator* (const Vector<T>) const;
	T& operator[] (size_t index) { return _array[index]; }
	friend std::ostream& operator<< <T>(std::ostream& stream, const Vector<T>& _vector);
	friend const Vector<T> operator/ (const T& scalar, const Vector<T>& vector);
	friend std::istream& operator>> <T> (std::istream& stream, const Vector<T>& _vector);
};

template <typename T>
std::ostream& operator<< (std::ostream& stream, const Vector<T>& _vector) {
	for (size_t i = 0; i < _vector.count; i++)
	{
		stream << std::setw(SETW)<< _vector._array[i];
	}
	return stream;
}

template <typename T>
std::istream& operator>> (std::istream& stream, const Vector<T>& _vector) {
	for (size_t i = 0; i < _vector.count; i++)
	{
		stream >> _vector._array[i];
	}
	return stream;
}

template <typename T>
const T Vector<T>::operator* (const Vector<T> _vector) const {
	size_t min = count < _vector.count ? count : _vector.count;
	T temp = static_cast<T>(0);
	for (size_t i = 0; i < min; i++)
	{
		temp += _array[i] * _vector._array[i];
	}
	return temp;
}

template <typename T>
Vector<T>::Vector<T>(const Vector<T>& _vector) {
	this->count = _vector.count;
	this->_array = new T[count];
	memcpy(_array, _vector._array, (count * sizeof(T)));
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& _vector) {
	if (_array != nullptr) {
		delete[] _array;
	}
	count = _vector.count;
	_array = new T[count];
	for (size_t i = 0; i < count; i++)
	{
		_array[i] = _vector._array[i];
	}
	return *this;
}

template <typename T>
const Vector<T> Vector<T>::operator+ (const Vector<T>& _vector) const {
	size_t max = count > _vector.count ? count : _vector.count;
	size_t min = count < _vector.count ? count : _vector.count;
	Vector<T> temp(max);
	size_t i;
	for (i = 0; i < min; i++)
	{
		temp._array[i] = _array[i] + _vector._array[i];
	}
	for (; i < count; i++)
	{
		temp._array[i] = _array[i];
	}
	for (; i < _vector.count; i++)
	{
		temp._array[i] = _vector._array[i];
	}
	return temp;
}

template <typename T>
Vector<T>& Vector<T>::operator+= (const Vector<T>& _vector) {
	*this = *this + _vector;
	return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator-= (const Vector<T>& _vector) {
	*this = *this - _vector;
	return *this;
}

template <typename T>
const Vector<T> Vector<T>::operator- (const Vector<T>& _vector) const {
	size_t max = count > _vector.count ? count : _vector.count;
	size_t min = count < _vector.count ? count : _vector.count;
	Vector<T> temp(max);
	for (size_t i = 0; i < min; i++)
	{
		temp._array[i] = _array[i] - _vector._array[i];
	}
	for (size_t i = 0; i < count; i++)
	{
		temp._array[i] = _array[i];
	}
	for (size_t i = 0; i < _vector.count; i++)
	{
		temp._array[i] = _vector._array[i];
	}
	return temp;
}

template <typename T>
const Vector<T> Vector<T>::operator* (const T& scalar) const {
	Vector<T> temp(count);
	for (size_t i = 0; i < count; i++)
	{
		temp[i] = _array[i] * scalar;
	}
	return temp;
}
template <typename T>
const Vector<T> operator* (const T& scalar, const Vector<T> right) {
	return right * scalar;
}

template <typename T>
const Vector<T> Vector<T>::operator/ (const T& scalar) const {
	Vector<T> temp(count);
	for (size_t i = 0; i < count; i++)
	{
		temp[i] = _array[i] / scalar;
	}
	return temp;
}

template <typename T>
const Vector<T> operator/ (const T& scalar, const Vector<T>& _vector) {
	Vector<T> temp(_vector.count);
	for (size_t i = 0; i < _vector.count; i++)
	{
		temp[i] = scalar / _vector._array[i];
	}
	return temp;
}

template <typename T>
Vector<T>& Vector<T>::operator*= (const T& scalar) {
	*this = *this * scalar;
	return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator/= (const T& scalar) {
	*this = *this / scalar;
	return *this;
}

template <typename T>
const Vector<T>& Vector<T>::operator++() {
	for (size_t i = 0; i < count; i++)
	{
		++_array[i];
	}
	return *this;
}

template <typename T>
const Vector<T> Vector<T>::operator++(int) {
	Vector<T> temp(*this);
	for (size_t i = 0; i < count; i++)
	{
		_array[i]++;
	}
	return temp;
}

template <typename T>
const bool Vector<T>::operator==(const Vector<T>& _vector) const {
	if (count != _vector.count)
		return false;
	for (size_t i = 0; i < count; i++)
	{
		if (_array[i] != _vector._array[i])
			return false;
	}
	return true;
}
template <typename T>
const bool Vector<T>::operator!=(const Vector<T>& _vector) const {
	return !(*this == _vector);
}

template <typename T>
void Vector<T>::resize(size_t size) {
	Vector<T> temp(*this);
	if (_array != nullptr) {
		delete[] _array;
	}
	_array = new T[size];
	size_t min = size < count ? size : count;
	memcpy(_array, temp._array, (min * sizeof(T)));
	count = size;
}

template <typename T>
const bool Vector<T>::operator<= (const Vector<T>& _vector) const {
	return !(*this > _vector);
}

template <typename T>
const bool Vector<T>::operator>= (const Vector<T>& _vector) const {
	return !(*this < _vector);
}

template <typename T>
const bool Vector<T>::operator< (const Vector<T>& _vector) const {
	if (count > _vector.count)
		return false;
	if (count < _vector.count)
		return true;
	for (size_t i = 0; i < count; i++)
	{
		if (_array[i] < _vector._array[i])
			return true;
		else if (_array[i] > _vector._array[i])
			return false;
	}
	return false;
}

template <typename T>
const bool Vector<T>::operator> (const Vector<T>& _vector) const {
	if (count > _vector.count)
		return true;
	if (count < _vector.count)
		return false;
	for (size_t i = 0; i < count; i++)
	{
		if (_array[i] > _vector._array[i])
			return true;
		else if (_array[i] < _vector._array[i])
			return false;
	}
	return false;
}

template <typename T>
void Vector<T>::push_back(const T& element) {
	resize(count + 1);
	getBack() = element;
}