#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

void PmergeMe::process(std::vector<int>& vec, std::deque<int>& deq) {
	printContainer("Before:", vec);

	clock_t startVec = clock();
	fordJohnsonSort(vec, 0);
	clock_t endVec = clock();

	clock_t startDeq = clock();
	fordJohnsonSort(deq, 0);
	clock_t endDeq = clock();

	printContainer("After: ", vec);

	double vecTime = 1000000.0 * (endVec - startVec) / CLOCKS_PER_SEC;	
	std::cout << "Time to process a range of " << vec.size()
		<< " elements with std::vector : " << vecTime << " us" << std::endl;

	double deqTime = 1000000.0 * (endDeq - startDeq) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << deq.size()
		<< " elements with std::deque  : " << deqTime << " us" << std::endl;
}

std::vector<size_t> PmergeMe::jacobsthalInsertionOrder(size_t size)
{
	std::vector<size_t> order;

	if (size == 0)
		return order;

	size_t j0 = 0, j1 = 1;

	while (j1 < size)
	{
		if (std::find(order.begin(), order.end(), j1) == order.end())
			order.push_back(j1);

		size_t next = j1 + 2 * j0;
		j0 = j1;
		j1 = next;
	}
	// std::cout << "jacob  :";
	// printContainer("", order);

	std::vector<bool> used(size, false);
	for (std::vector<size_t>::const_iterator it = order.begin(); it != order.end(); ++it)
		used[*it] = true;

	for (size_t i = 0; i < size; ++i)
		if (!used[i])
			order.push_back(i);

	// std::cout << "order  :";
	// printContainer("", order);
	return order;
}
