#pragma once

#include <cstddef>	 // For size_t
#include <stdexcept> // for std::exception

template <typename T> class Array {
  private:
	T* _data;
	unsigned int _size;

  public:
	// Default constructor
	Array() : _data(NULL), _size(0) {}

	// Constructor with size
	Array(unsigned int n) : _data(new T[n]), _size(n) {}

	// Copy constructor
	Array(const Array& other) : _data(NULL), _size(0) { *this = other; }

	// Copy assignment
	Array& operator=(const Array& other) {
		if (this != &other) {
			delete[] _data;
			_size = other._size;
			_data = new T[_size];
			for (unsigned int i = 0; i < _size; ++i)
				_data[i] = other._data[i];
		}
		return *this;
	}

	// Destructor
	~Array() { delete[] _data; }

	// Element access
	T& operator[](unsigned int index) {
		if (index >= _size)
			throw std::out_of_range("Index out of bounds");
		return _data[index];
	}

	// Const element access
	const T& operator[](unsigned int index) const {
		if (index >= _size)
			throw std::out_of_range("Index out of bounds");
		return _data[index];
	}

	// Size getter
	unsigned int size() const { return _size; }
};
