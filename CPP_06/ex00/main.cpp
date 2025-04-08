#include "ScalarConverter.hpp"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cout << "./ex00 [char/int/float/double]" << std::endl;
		return (1);
	}
	std::cout << std::fixed << std::setprecision(1); // (9)
	ScalarConverter::convert(argv[1]);
	// a
	// Z
	// *
	// 0
	// 1.123456789 // (9)
	// -2147483648
	//  +inff
	// 42..0
	return (0);
}
