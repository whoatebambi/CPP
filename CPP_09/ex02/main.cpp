#include "PmergeMe.hpp"

int	parseIntArg(const std::string& arg) {
	if (arg.empty())
		throw std::runtime_error("Error: empty input => " + arg);
	for (size_t i = 0; i < arg.length(); ++i) {
		if (!std::isdigit(static_cast<unsigned char>(arg[i])))
			throw std::runtime_error("Error: non-digit character => " + arg);
	}
	unsigned long value = std::strtoul(arg.c_str(), NULL, 10);
	if (value > static_cast<unsigned long>(INT_MAX))
		throw std::runtime_error("Error: integer overflow => " + arg);
	return static_cast<int>(value);
}

int	main(int ac, char **av) {
	if (ac < 2) {
		std::cout << "Error: usage ./PmergeMe [int] [int] ..." << std::endl;
		// ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
		return 1;
	}
	try {
		std::vector<int> vecRange;
		std::deque<int> deqRange;
		for (int i = 1; i < ac; ++i) {
			int number = parseIntArg(av[i]);
			vecRange.push_back(number);
			deqRange.push_back(number);
		}
		PmergeMe sorter;
		sorter.process(vecRange, deqRange);		
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
