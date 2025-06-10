#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#define FILENAME "data.csv"
#define HEADER "date,exchange_rate"
#define HEADER_INPUT "date | value"

#include <algorithm>	// for pour remove_if
#include <cstdlib>		// for pour atoi, strtod
#include <ctime>		// for time_t, tm, mktime, localtime
#include <fstream>
#include <iomanip>		// for std::setprecision, std::fixed
#include <iostream>
#include <map>
#include <sstream>

class BitcoinExchange {
	private:
		std::map<time_t, double> _db;

	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange&	operator=(const BitcoinExchange& other);

		void	loadDatabase(const std::string& filename);
		size_t	findSeparator(const std::string& line, const char& c);
		time_t	stringToDate(const std::string& input, size_t index); // const?
		std::string	dateToString(time_t timestamp);
		bool	isValidDateFormat(const std::string& input);
		double	convertDouble(const std::string& line, const std::string& input);

		void	processInput(const std::string& filename);
};

#endif
