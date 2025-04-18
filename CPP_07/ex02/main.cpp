#include "Array.hpp"

#include <iostream>
#include <string>

int main() {
	try {
		Array<int> b = Array<int>(5);
		(b)[0] = 42;
		std::cout << "a _size  = " << b.size() << std::endl;
		std::cout << "a[0]     = " << (b)[0] << std::endl;
		std::cout << "a[10]    = " << (b)[10] << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	Array<std::string> stringArray(3);
	std::cout << "\nstringArray size: " << stringArray.size() << std::endl;
	for (std::size_t i = 0; i < stringArray.size(); ++i)
		stringArray[i] = 65 + i;
	for (std::size_t i = 0; i < stringArray.size(); ++i)
		std::cout << "a[" << i << "] = " << stringArray[i] << std::endl;

	Array<std::string> copystrArray(stringArray);
	std::cout << "\ncopystrArray : "  << std::endl;	
	for (std::size_t i = 0; i < copystrArray.size(); ++i) 
		std::cout << copystrArray[i] << std::endl;

	copystrArray[0] = "AAAAAA";
	stringArray = copystrArray;
	for (std::size_t i = 0; i < stringArray.size(); ++i)
		std::cout << "a[" << i << "] = " << stringArray[i] << std::endl;

	return 0;
}
