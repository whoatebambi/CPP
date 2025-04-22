#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>

class Span {
	private:
		std::vector<int> _data;
		unsigned int _maxSize;
		Span();

	public:
		Span(unsigned int N);
		~Span();
		Span(const Span& other);
		Span& operator=(const Span& other);
		int& operator[](unsigned int index);

		void addNumber(unsigned int nb);
		int shortestSpan() const;
		int longestSpan() const;

		template <typename Iterator> void addNumbers(Iterator begin, Iterator end);
};

#include "Span.tpp"

#endif
