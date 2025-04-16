#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	// std::cout << "BitcoinExchange constructor called" << std::endl;
}

BitcoinExchange::~BitcoinExchange() {
	// std::cout << "BitcoinExchange destructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	std::cout << "BitcoinExchange copy constructor called" << std::endl;
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	std::cout << "BitcoinExchange assignment operator called" << std::endl;
	if (this != &other) {
		*this = other;
	}
	return *this;
}

void BitcoinExchange::loadDatabase(const std::string& filename) {
	std::ifstream file(filename);
	if (!file)
		throw std::runtime_error("Error: could not open database file.");
	std::string line;

	std::getline(file, line);
	if (line != HEADER)
		throw std::runtime_error("Error: no header detected.");

	while (std::getline(file, line)) {
		size_t index = findSeparatorDb(line);
		std::string date = convertDate(line, index);
		double rate = convertDouble((line.substr(index + 1)));
		// std::cout << "date : " << date << std::endl;
		// std::cout << "rate : " << rate << std::endl;
		this->_db[date] = rate;
	}
	file.close(); // needed?
	std::cout << "Database loaded." << std::endl;
}

size_t BitcoinExchange::findSeparatorDb(const std::string& line) {
	size_t index = line.find(',');
	if (index == std::string::npos) // -1
		throw std::runtime_error("Error: no separator found.");
	return index;
}

std::string BitcoinExchange::convertDate(const std::string& input, size_t index) {
	std::string date = input.substr(0, index);
	// sanitize and throw
	// 2009-01-02,0
	// 2011-10-23,3.31
	// 2011-10-26,3
	return date;
}

double BitcoinExchange::convertDouble(const std::string& input) {
	char* end;
	double f = strtod(input.c_str(), &end);

	if (end == input.c_str())
		throw std::runtime_error("Error: conversion to double failed.");
	// check if negative
	return f;
}

void BitcoinExchange::processInput(const std::string& filename) {
	std::ifstream file(filename);
	if (!file)
		throw std::runtime_error("Error: could not open input file.");
	std::string line;

	std::getline(file, line);
	if (line != HEADER_INPUT)
		throw std::runtime_error("Error: no header detected.");

	// std::cout << std::fixed << std::setprecision(2);

	while (std::getline(file, line)) {
		size_t index = line.find('|');
		if (index == std::string::npos) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::string date = convertDate(line, index);
		double value = convertDouble((line.substr(index + 1)));
		if (value < 0) {
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000) {
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}
		// std::cout << date << " | " << value << std::endl;
		if (this->_db[date])
			std::cout << "MATCH " << date << " | " << this->_db[date] << std::endl;
		// this->_db[date] = rate;
	}
	file.close(); // needed?
	std::cout << "Input processed." << std::endl;
}

// Votre programme doit afficher sur la sortie standard le résultat de la valeur multipliée
// par le taux de change en fonction de la date indiquée dans votre base de données.

// $> ./btc input.txt
// 2011-01-03 => 3 = 0.9
// 2011-01-03 => 2 = 0.6
// 2011-01-03 => 1 = 0.3
// 2011-01-03 => 1.2 = 0.36
// 2011-01-09 => 1 = 0.32
// Error: not a positive number.
// Error: bad input => 2001-42-42
// 2012-01-11 => 1 = 7.1
// Error: too large a number.
// $>

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