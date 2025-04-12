#include "Span.hpp"

#include <cstdlib>
#include <iostream>

int main() {
	// try {
	// 	Span intVec(5);
	// 	intVec.addNumber(5);
	// 	intVec.addNumber(50);
	// 	intVec.addNumber(500);
	// 	// intVec.addNumber(5101);
	// 	// intVec.addNumber(504);
	// 	// std::cout << "intVec[0] = " << intVec[0] << std::endl;
	// 	// std::cout << "intVec[1] = " << intVec[1] << std::endl;
	// 	// std::cout << "intVec[2] = " << intVec[2] << std::endl;
	// 	std::cout << "shortest = " << intVec.shortestSpan() << std::endl;
	// 	std::cout << "longest = " << intVec.longestSpan() << std::endl;
	// } catch (const std::exception& e) {
	// 	std::cout << e.what() << std::endl;
	// }

	try {
		std::vector<int> tmp;
		unsigned int size = 10000;
		std::srand(time(NULL)); // Initialise la seed pour rand()
		for (unsigned int i = 0; i < size; ++i) {
			tmp.push_back(std::rand() % 100);
		}
		Span intVec(size);
		intVec.addRange(tmp.begin(), tmp.end());
		std::cout << "intVec[9999] = " << intVec[9999] << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}

// int main()
// {
// 	Span sp = Span(5);
// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
// 	return 0;
// }