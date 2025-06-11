#include "RPN.hpp"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "Error" << std::endl;
		return 1;
	}

	try {
		int result = RPN::parseInput(argv[1]);
		std::cout << result << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}

// ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
// 42
// ./RPN "7 7 * 7 -"
// 42
// ./RPN "1 2 * 2 / 2 * 2 4 - +"
// 0
// ./RPN "(1 + 1)"
// Error