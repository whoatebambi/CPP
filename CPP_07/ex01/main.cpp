#include "iter.hpp"

#include <iostream>
#include <string>

template <typename T>
void printElement(T& x) {
	std::cout << x << std::endl;
}

template <typename T>
void increment(T& x) {
	x += 1;
}

int main() {
	int arr[] = {1, 2, 3, 4, 5};
	std::cout << "Original int array:\n";
	iter(arr, 5, printElement);
	std::cout << "\nIncremented int array:\n";
	iter(arr, 5, increment);
	iter(arr, 5, printElement);

	char charArr[] = {'a', 'b', 'c', 'd', 'e'};
	std::cout << "\nOriginal char array:\n";
	iter(charArr, 5, printElement);
	std::cout << "\nIncremented char array:\n";
	iter(charArr, 5, increment);
	iter(charArr, 5, printElement);

	std::string strArr[] = {"apple", "banana", "cherry"};
	std::cout << "\nString array:\n";
	iter(strArr, 3, printElement);

	return 0;
}
