#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#define FILENAME "data.csv"
#define HEADER "date,exchange_rate"
#define HEADER_INPUT "date | value"

#include <iostream>
#include <map>
#include <fstream>
#include <iomanip> // for std::setprecision, std::fixed

class BitcoinExchange {
	private:
		std::map<std::string, double> _db;

	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange&	operator=(const BitcoinExchange& other);

		void	loadDatabase(const std::string& filename);
		size_t	findSeparatorDb(const std::string& line);
		std::string	convertDate(const std::string& input, size_t index); // const?
		double	convertDouble(const std::string& input);

		void	processInput(const std::string& filename);
};

#endif