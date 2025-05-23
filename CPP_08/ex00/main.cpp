#include "easyfind.hpp"

#include <iostream>
#include <exception>
#include <vector>
#include <list>
#include <set>
#include <deque>

int main() {
	int arr[] = {1, 2, 3};
	int value = 42;

	// Sequence containers (c++98 compatible)
	// (no associative containers like set, map...)
	std::vector<int> v(arr, arr + 3);
	std::list<int>   l(arr, arr + 3);
	std::deque<int>  d(arr, arr + 3);

	try {
		std::cout << "--- Testing std::vector<int> ---" << std::endl;
		std::vector<int>::iterator vV =  easyfind(v, value);
		std::cout << "Found match: " << *vV << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try {
		std::cout << "--- Testing std::list<int> ---" << std::endl;
		std::list<int>::iterator lV =  easyfind(l, value);
		std::cout << "Found match: " << *lV << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try {
		std::cout << "--- Testing std::deque<int> ---" << std::endl;
		std::deque<int>::iterator dV =  easyfind(d, value);
		std::cout << "Found match: " << *dV << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}
