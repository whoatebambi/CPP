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
	std::ifstream file(filename.c_str());
	if (!file)
		throw std::runtime_error("Error: could not open database file.");
	std::string line;

	std::getline(file, line);
	if (line != HEADER)
		throw std::runtime_error("Error: no header detected.");

	while (std::getline(file, line)) {
		size_t index = findSeparator(line, ',');
		time_t date = stringToDate(line, index);
		double rate = convertDouble((line.substr(index + 1)));
		// std::cout << "date : " << date << std::endl;
		// std::cout << "rate : " << rate << std::endl;
		this->_db[date] = rate;
	}
	file.close(); // needed?
	std::cout << "Database loaded." << std::endl;
}

size_t BitcoinExchange::findSeparator(const std::string& line, const char& c) {
	size_t index = line.find(c);
	if (index == std::string::npos) // == -1
		throw std::runtime_error("Error: bad input => " + line);
	return index;
}

bool BitcoinExchange::isValidDateFormat(const std::string& date) {
	if (date.length() != 10)
		return false;

	for (int i = 0; i < 10; ++i) {
		if ((i >= 0 && i <= 3) || (i >= 5 && i <= 6) || (i >= 8 && i <= 9)) {
            if (!std::isdigit(date[i]))
                return false;
        }
		else if (i == 4 || i == 7) {
            if (date[i] != '-')
                return false;
        }
		else
            return false; // shouldn't reach here
	}
	return true;
}

time_t BitcoinExchange::stringToDate(const std::string& input, size_t index) {
	std::string date = input.substr(0, index);
	date.erase(std::remove_if(date.begin(), date.end(), ::isspace), date.end());

	if (!isValidDateFormat(date))
		throw std::runtime_error("Error: bad input => " + input);

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	
	tm timeInfo = {};
	timeInfo.tm_year = year - 1900;
	timeInfo.tm_mon = month - 1;
	timeInfo.tm_mday = day;
	
	time_t dateTime = mktime(&timeInfo);
	if (dateTime == -1 || timeInfo.tm_year != year - 1900
		|| timeInfo.tm_mon != month - 1 || timeInfo.tm_mday != day)
		throw std::runtime_error("Error: bad input => " + input);

	return dateTime;
}

double BitcoinExchange::convertDouble(const std::string& input) {
	char* end;
	double f = strtod(input.c_str(), &end);

	if (end == input.c_str())
		throw std::runtime_error("Error: conversion to double failed.");
	if (f < 0)
		throw std::runtime_error("Error: not a positive number.");
	return f;
}

std::string BitcoinExchange::dateToString(time_t timestamp) {
    tm* timeInfo = std::localtime(&timestamp);

    std::ostringstream oss;
    oss << (timeInfo->tm_year + 1900) << "-"
        << std::setw(2) << std::setfill('0') << (timeInfo->tm_mon + 1) << "-"
        << std::setw(2) << std::setfill('0') << timeInfo->tm_mday;

    return oss.str();
}

void BitcoinExchange::processInput(const std::string& filename) {
	std::ifstream file(filename.c_str());
	if (!file)
		throw std::runtime_error("Error: could not open input file.");
	std::string line;

	std::getline(file, line);
	if (line != HEADER_INPUT)
		throw std::runtime_error("Error: no header detected.");

	while (std::getline(file, line)) {
		try {
			size_t index = findSeparator(line, '|');
			time_t date = stringToDate(line, index);
			double value = convertDouble((line.substr(index + 1)));
			if (value > 1000) {
				throw std::runtime_error("Error: too large a number.");}
			// std::cout << date << " | " << value << std::endl;
			if (_db.find(date) != _db.end())
				std::cout << "MATCH " << dateToString(date) << " | " << _db[date] << std::endl;
			else {
				
			}


		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		
	}
	file.close(); // needed?
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