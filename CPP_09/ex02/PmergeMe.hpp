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
	private:
		PmergeMe(const PmergeMe& other);
		PmergeMe&	operator=(const PmergeMe& other);

	public:
		PmergeMe();
		~PmergeMe();
		void process(std::vector<int>& vec, std::deque<int>& deq);
		std::vector<size_t> jacobsthalInsertionOrder(size_t size);

		template <typename Container>
		void fordJohnsonSort(Container& container, int depth);
		template <typename T>
		void printContainer(const std::string& text, const T& container);
};

#include "PmergeMe.tpp"

#endif