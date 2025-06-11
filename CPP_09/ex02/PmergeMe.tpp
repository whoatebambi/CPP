#include "PmergeMe.hpp"

template <typename Container>
void PmergeMe::fordJohnsonSort(Container& container, int depth) {
	if (container.size() <= 1)
		return;

	(void)depth;
	// std::string indent(depth * 2, ' ');
	// std::cout << indent << "Entering: ";
	// printContainer("", container);

	Container big;
	Container small;

	for (size_t i = 0; i + 1 < container.size(); i += 2) {
		int a = container[i];
		int b = container[i + 1];
		if (a > b) {
			big.push_back(a);
			small.push_back(b);
		} else {
			big.push_back(b);
			small.push_back(a);
		}
	}
	// std::cout << indent << "big     : ";
	// printContainer("", big);
	// std::cout << indent << "small   : ";
	// printContainer("", small);

	fordJohnsonSort(big, depth + 1);

	// for (size_t i = 0; i < small.size(); ++i) {
	// 	typename Container::iterator pos = std::lower_bound(big.begin(), big.end(), small[i]);
	// 	big.insert(pos, small[i]);
	// }

	std::vector<size_t> order = jacobsthalInsertionOrder(small.size());
	for (size_t i = 0; i < order.size(); ++i) {
		int value = small[order[i]];
		typename Container::iterator pos = std::lower_bound(big.begin(), big.end(), value);
		big.insert(pos, value);
		// std::cout << indent << "jacob : ";
		// printContainer("", big);
	}

	if (container.size() % 2 == 1) {
		int last = container.back();
		typename Container::iterator pos = std::lower_bound(big.begin(), big.end(), last);
		big.insert(pos, last);
	}
	container = big;
	// std::cout << indent << "Sorted  :";
	// printContainer("", container);
}

template <typename T>
void PmergeMe::printContainer(const std::string& text, const T& container) {
	std::cout << text << " ";
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}
