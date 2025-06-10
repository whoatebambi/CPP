#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}

	try {
		BitcoinExchange db;
		db.loadDatabase(FILENAME);
		db.processInput(av[1]); // keep it rolling even though it catches errors
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
