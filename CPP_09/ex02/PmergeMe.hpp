#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <exception>
#include <climits>   // Pour INT_MAX
#include <cstdlib>   // Pour std::strtoul
#include <ctime>

class PmergeMe {
public:
	PmergeMe();
	~PmergeMe();

	void process(std::vector<int>& vec, std::deque<int>& deq);

private:
	// void fordJohnsonSort(std::vector<int>& vec);
	// void fordJohnsonSort(std::deque<int>& deq);
	void fordJohnsonSort(std::vector<int>& vec, int depth = 0);
	void fordJohnsonSort(std::deque<int>& deq, int depth = 0);

	template <typename T>
	void printContainer(const std::string& text, const T& container);
};

#endif