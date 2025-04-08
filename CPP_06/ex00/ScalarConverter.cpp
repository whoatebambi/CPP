#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
	std::cout << "ScalarConverter constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "ScalarConverter destructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	std::cout << "ScalarConverter copy constructor called" << std::endl;
	*this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs) {
	std::cout << "ScalarConverter assignment operator called" << std::endl;
	if (this == &rhs)
		return *this;

	(void) rhs;
	return *this;
}

bool detectPseudo(const std::string& input) {
	if (input == "nan" || input == "+inf" || input == "-inf") {
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: " << input << "f\n";
		std::cout << "double: " << input << std::endl;
		return true;
	} else if (input == "nanf" || input == "+inff" || input == "-inff") {
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: " << input << "\n";
		std::cout << "double: " << input.substr(0, input.size() - 1) << std::endl;
		return true;
	}
	return false;
}

bool detectChar(const std::string& input) {
	if (input.length() == 1 && std::isprint(static_cast<unsigned char>(input[0])) &&
		!std::isdigit(static_cast<unsigned char>(input[0]))) {
		return true;
	}
	return false;
}

bool detectInt(const std::string& input) {
	if (input.empty())
		return false;
	size_t i = 0;

	if (input[i] == '+' || input[i] == '-') {
		++i;
		if (input.length() == 1)
			return false;
	}

	for (; i < input.length(); ++i) {
		if (!std::isdigit(static_cast<unsigned char>(input[i])))
			return false;
	}
	return true;
}

bool detectFloat(const std::string& input) {
	if (input.empty() || input[input.length() - 1] != 'f')
		return false;

	std::string core = input.substr(0, input.length() - 1);
	if (core.empty())
		return false;

	size_t i = 0;
	bool dotSeen = false;
	bool digitSeen = false;

	if (core[i] == '+' || core[i] == '-') {
		++i;
		if (core.length() == 1)
			return false;
	}

	for (; i < core.length(); ++i) {
		if (std::isdigit(static_cast<unsigned char>(core[i])))
			digitSeen = true;
		else if (core[i] == '.') {
			if (dotSeen)
				return false;
			dotSeen = true;
		} else
			return false;
	}

	return digitSeen && dotSeen;
}

bool detectDouble(const std::string& input) {
	if (input.empty())
		return false;

	size_t i = 0;
	bool dotSeen = false;
	bool digitSeen = false;

	if (input[i] == '+' || input[i] == '-') {
		++i;
		if (input.length() == 1)
			return false;
	}

	for (; i < input.length(); ++i) {
		if (std::isdigit(static_cast<unsigned char>(input[i])))
			digitSeen = true;
		else if (input[i] == '.') {
			if (dotSeen)
				return false;
			dotSeen = true;
		} else
			return false;
	}

	return digitSeen && dotSeen;
}

void convertChar(const std::string& input) {
	char c = input[0];

	std::cout << "char: '" << c << "'\n";

	std::cout << "int: " << static_cast<int>(c) << "\n";

	// std::cout << std::fixed << std::setprecision(9);
	std::cout << "float: " << static_cast<float>(c) << "f\n";

	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void convertInt(const std::string& input) {
	errno = 0;
	char* endPtr = NULL;
	long val = std::strtol(input.c_str(), &endPtr, 10);

	if (errno == ERANGE || val < INT_MIN || val > INT_MAX) {
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: impossible\n";
		std::cout << "double: impossible" << std::endl;
		return;
	}

	int n = static_cast<int>(val);

	if (n < 0 || n > 127)
		std::cout << "char: impossible\n";
	else if (!std::isprint(static_cast<unsigned char>(n)))
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << static_cast<char>(n) << "'\n";

	std::cout << "int: " << n << "\n";

	// std::cout << std::fixed << std::setprecision(9);
	std::cout << "float: " << static_cast<float>(n) << "f\n";

	std::cout << "double: " << static_cast<double>(n) << std::endl;
}

void convertFloat(const std::string& input) {
	errno = 0;
	char* endPtr = NULL;
	float f = std::strtof(input.c_str(), &endPtr);

	if (errno == ERANGE) {
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: impossible\n";
		std::cout << "double: impossible\n";
		return;
	}

	if (std::isnan(f) || std::isinf(f) || f < 0 || f > 127)
		std::cout << "char: impossible\n";
	else if (!std::isprint(static_cast<unsigned char>(f)))
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << static_cast<char>(f) << "'\n";

	if (std::isnan(f) || f < static_cast<float>(INT_MIN) || f > static_cast<float>(INT_MAX))
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(f) << "\n";

	// std::cout << std::fixed << std::setprecision(9);
	std::cout << "float: " << f << "f\n";

	std::cout << "double: " << static_cast<double>(f) << "\n";
}

void convertDouble(const std::string& input) {
	errno = 0;
	char* endPtr = NULL;

	double d = std::strtod(input.c_str(), &endPtr);

	if (errno == ERANGE) {
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: impossible\n";
		std::cout << "double: impossible\n";
		return;
	}

	if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
		std::cout << "char: impossible\n";
	else if (!std::isprint(static_cast<unsigned char>(d)))
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << static_cast<char>(d) << "'\n";

	if (std::isnan(d) || d < INT_MIN || d > INT_MAX)
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(d) << "\n";

	// std::cout << std::fixed << std::setprecision(9);
	std::cout << "float: " << static_cast<float>(d) << "f\n";

	std::cout << "double: " << d << "\n";
}

void ScalarConverter::convert(const std::string& input) {
	bool isPseudo = false;
	bool isChar = false;
	bool isInt = false;
	bool isFloat = false;
	bool isDouble = false;

	isPseudo = detectPseudo(input);
	if (isPseudo)
		return;

	isChar = detectChar(input);
	if (!isChar) {
		isInt = detectInt(input);
		if (!isInt) {
			isFloat = detectFloat(input);
			if (!isFloat) {
				isDouble = detectDouble(input);
			}
		}
	}

	if (!isChar && !isInt && !isFloat && !isDouble)
		std::cout << "Conversion is impossible." << std::endl;

	if (isChar)
		convertChar(input);
	else if (isInt)
		convertInt(input);
	else if (isFloat)
		convertFloat(input);
	else if (isDouble)
		convertDouble(input);
}
