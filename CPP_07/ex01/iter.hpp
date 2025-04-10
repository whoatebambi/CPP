#pragma once

#include <cstddef> // For size_t

template <typename T>
void iter(T* array, size_t length, void (*ptrFt)(T&)) {
	for (size_t i = 0; i < length; ++i)
		ptrFt(array[i]);
}

template <typename T>
void iter(T* array, size_t length, void (*ptrFt)(T const&)) {
	for (size_t i = 0; i < length; ++i)
		ptrFt(array[i]);
}
