#include "BitcoinExchange.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <map>

void	fillDbRef(std::map<std::string, float> &dbRef, std::ifstream &file) {
	std::string line;
	
	while (std::getline(file, line)) {
		std::string date;
		float nb;
		size_t index = line.find(',');
		if (index != std::string::npos) {
			date = line.substr(0, index);
			
			// std::cout << "line = " << line << std::endl;
		}
		dbRef.insert(std::pair<std::string, float>(date, nb));
	}
	
}

int main(int ac, char **av) {
	std::cout << "Hello, world!" << std::endl;
	// if (ac != 2) {
	// 	std::cout << "Error: could not open file." << std::endl;
	// 	return 1;
	// }
	(void)ac;
	(void)av;

	// parse database reference
	std::string filename = "data.csv";
	std::ifstream file(filename);
	if (!file) {
		std::cerr << "Error: could not open " << filename << std::endl;
		return 1;
	}
	
	std::map<std::string, float> dbRef;
	fillDbRef(dbRef, file);
	
	file.close();

	// for (size_t i = 0; i < 10; ++i) {
	// 	std::cout << "line[" << i << "] = " << dbRef[i] << std::endl;
	// }

	// date,exchange_rate
	// 2009-01-02,0
	// 2011-10-23,3.31
	// 2011-10-26,3
	
	// parse av[1];]

	return 0;
}
