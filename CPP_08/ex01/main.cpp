#include "Span.hpp"

#include <cstdlib>
#include <iostream>

int main() {
	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "sp[6] = " << sp[6] << std::endl;
		std::cout << "shortest = " << sp.shortestSpan() << std::endl;
		std::cout << "longest = " << sp.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::vector<int> tmp;
		unsigned int size = 10000;
		std::srand(time(NULL)); // Init the seed for rand()
		for (unsigned int i = 0; i < size - 3; ++i) {
			tmp.push_back(std::rand() % 100);
		}
		Span sp(size);
		sp.addNumbers(tmp.begin(), tmp.end());

		int arr[] = {1, 2, 3};
		sp.addNumbers(arr, arr + 3);

		std::cout << "sp[9999] = " << sp[9999] << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
