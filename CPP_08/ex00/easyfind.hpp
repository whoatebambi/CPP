#pragma once

#include <iostream>
#include <exception>

#include "easyfind.tpp"

template <typename T> typename T::iterator easyfind(T& container, int value);
