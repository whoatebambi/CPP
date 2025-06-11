#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}

	try {
		BitcoinExchange db;
		db.loadDatabase(FILENAME);
		db.processInput(av[1]);
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}

// tar -xvzf cpp_09.tgz

// input.txt
// date | value
// 2011-01-03 | 3
// 2011-01-03 | 2
// 2011-01-03 | 1
// 2011-01-03 | 1.2
// 2011-01-09 | 1
// 2012-01-11 | -1
// 2001-42-42
// 2012-01-11 | 1
// 2012-01-11 | 2147483648