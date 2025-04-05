#include "ScalarConverter.hpp"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cout << "./ex00 [char/int/float/double]" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}

// #include <vector>

// int main() {
// 	std::vector<std::string> tests;
// 	tests.push_back("a");
// 	tests.push_back("Z");
// 	tests.push_back("*");

// 	tests.push_back("0");
// 	tests.push_back("42");
// 	tests.push_back("-42");
// 	tests.push_back("2147483647");
// 	tests.push_back("-2147483648");
// 	tests.push_back("2147483648");

// 	tests.push_back("42.0f");
// 	tests.push_back("-3.14f");
// 	tests.push_back("0.0f");
// 	tests.push_back(".5f");
// 	tests.push_back("+inff");
// 	tests.push_back("-inff");
// 	tests.push_back("nanf");

// 	tests.push_back("42.0");
// 	tests.push_back("-3.14");
// 	tests.push_back("0.0");
// 	tests.push_back(".5");
// 	tests.push_back("+inf");
// 	tests.push_back("-inf");
// 	tests.push_back("nan");

// 	tests.push_back("");
// 	tests.push_back("123abc");
// 	tests.push_back("42f");
// 	tests.push_back("abc");
// 	tests.push_back("++42");
// 	tests.push_back("42..0");

// 	for (size_t i = 0; i < tests.size(); ++i) {
// 		std::cout << "Input: \"" << tests[i] << "\"\n";
// 		ScalarConverter::convert(tests[i]);
// 		std::cout << "--------------------------------------\n";
// 	}
// 	return 0;
// }
