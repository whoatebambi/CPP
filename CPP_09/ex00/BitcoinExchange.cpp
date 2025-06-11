#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	// std::cout << "BitcoinExchange constructor called" << std::endl;
}

BitcoinExchange::~BitcoinExchange() {
	// std::cout << "BitcoinExchange destructor called" << std::endl;
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
		try {
			size_t index = findSeparator(line, ',');
			time_t date = stringToDate(line, index);
			double rate = convertDouble(line, (line.substr(index + 1)));
			_db[date] = rate;
		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}

	if (_db.empty())
		throw std::runtime_error("Error: database is empty.");

	file.close();
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
            return false;
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

double BitcoinExchange::convertDouble(const std::string& line, const std::string& input) {
	char* end;
	double f = strtod(input.c_str(), &end);

	if (end == input.c_str())
		// throw std::runtime_error("Error: conversion to double failed.");
		throw std::runtime_error("Error: bad input => " + line);
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
			double value = convertDouble(line, (line.substr(index + 1)));

			if (value > 1000) {
				throw std::runtime_error("Error: too large a number.");}

			std::map<time_t, double>::const_iterator it = _db.lower_bound(date);
			if (it == _db.end() || it->first != date) {
				if (it == _db.begin())
					throw std::runtime_error("Error: no earlier date available.");
				--it;
			}
			std::cout << dateToString(date) << " => " << value << " = " << it->second * value << std::endl;

		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		
	}
	file.close();
}
