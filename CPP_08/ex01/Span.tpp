#include "Span.hpp"

template <typename Iterator>
void Span::addNumbers(Iterator begin, Iterator end) {
	// Compile-time check: will fail if Iterator is not really an iterator
	typedef typename std::iterator_traits<Iterator>::iterator_category category;
	(void)category();

	typename std::iterator_traits<Iterator>::difference_type dist = std::distance(begin, end);
	if (dist < 0)
		throw std::runtime_error("Invalid iterator range: begin is after end");

	if (static_cast<unsigned int>(dist) + _data.size() > _maxSize)
		throw std::runtime_error("Span is full");

	_data.insert(_data.end(), begin, end);
}
