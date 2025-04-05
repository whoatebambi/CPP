#pragma once

#include <cctype>
#include <cerrno>
#include <iomanip>
#include <iostream>
#include <string>

class ScalarConverter {
  private:
  public:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& rhs);

	static void convert(const std::string& input);
};
