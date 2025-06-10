#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

void PmergeMe::process(std::vector<int>& vec, std::deque<int>& deq) {
	printContainer("Before:", vec);

	clock_t startVec = clock();
	fordJohnsonSort(vec);
	clock_t endVec = clock();

	clock_t startDeq = clock();
	fordJohnsonSort(deq);
	clock_t endDeq = clock();

	printContainer("After: ", vec);

	double vecTime = 1000000.0 * (endVec - startVec) / CLOCKS_PER_SEC;	
	std::cout << "Time to process a range of " << vec.size()
		<< " elements with std::vector : " << vecTime << " us" << std::endl;

	double deqTime = 1000000.0 * (endDeq - startDeq) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << deq.size()
		<< " elements with std::deque :  " << deqTime << " us" << std::endl;
}

void PmergeMe::fordJohnsonSort(std::vector<int>& vec, int depth) {
	if (vec.size() <= 1)
		return;

	std::string indent(depth * 2, ' ');
	// std::cout << indent << "Entering  : ";
	// printContainer("", vec);

	std::vector<int> mainChain;
	std::vector<int> pending;

	for (size_t i = 0; i + 1 < vec.size(); i += 2) {
		int a = vec[i];
		int b = vec[i + 1];
		if (a > b) {
			mainChain.push_back(a);
			pending.push_back(b);
		} else {
			mainChain.push_back(b);
			pending.push_back(a);
		}
	}
	// std::cout << indent << "Entering M: ";
	// printContainer("", mainChain);
	// std::cout << indent << "Entering p: ";
	// printContainer("", pending);

	fordJohnsonSort(mainChain, depth + 1);

	for (size_t i = 0; i < pending.size(); ++i) {
		std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), pending[i]);
		mainChain.insert(pos, pending[i]);
	}

	if (vec.size() % 2 == 1) {
		int last = vec.back();
		std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), last);
		mainChain.insert(pos, last);
	}

	vec = mainChain;

	// std::cout << indent << "Sorted  :   ";
	// printContainer("", vec);
}

void PmergeMe::fordJohnsonSort(std::deque<int>& deq, int depth) {
	if (deq.size() <= 1)
		return;

	std::string indent(depth * 2, ' ');
	// std::cout << indent << "Entering: ";
	// printContainer("", deq);

	std::deque<int> mainChain;
	std::deque<int> pending;

	for (size_t i = 0; i + 1 < deq.size(); i += 2) {
		int a = deq[i];
		int b = deq[i + 1];
		if (a > b) {
			mainChain.push_back(a);
			pending.push_back(b);
		} else {
			mainChain.push_back(b);
			pending.push_back(a);
		}
	}

	fordJohnsonSort(mainChain, depth + 1);

	for (size_t i = 0; i < pending.size(); ++i) {
		std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), pending[i]);
		mainChain.insert(pos, pending[i]);
	}

	if (deq.size() % 2 == 1) {
		int last = deq.back();
		std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), last);
		mainChain.insert(pos, last);
	}

	deq = mainChain;

	// std::cout << indent << "Sorted:   ";
	// printContainer("", deq);
}

template <typename T>
void PmergeMe::printContainer(const std::string& text, const T& container) {
	std::cout << text << " ";
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}