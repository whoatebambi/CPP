#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#define FILENAME "data.csv"
#define HEADER "date,exchange_rate"
#define HEADER_INPUT "date | value"

#include <iostream>
#include <map>
#include <fstream>
#include <iomanip> // for std::setprecision, std::fixed
#include <sstream>

class BitcoinExchange {
	private:
		std::map<std::time_t, double> _db;

	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange&	operator=(const BitcoinExchange& other);

		void	loadDatabase(const std::string& filename);
		size_t	findSeparator(const std::string& line, const char& c);
		std::time_t	stringToDate(const std::string& input, size_t index); // const?
		std::string	dateToString(std::time_t timestamp);
		bool	isValidDateFormat(const std::string& input);
		double	convertDouble(const std::string& input);

		void	processInput(const std::string& filename);
};

#endif