#pragma once

#include <exception>
#include <iostream>
#include <limits>
#include <vector>

class Span {
  private:
	std::vector<int> _data;
	unsigned int _maxSize;

  public:
	Span();
	Span(unsigned int N);
	~Span();
	Span(const Span& other);
	Span& operator=(const Span& other);
	int& operator[](unsigned int index);

	void addNumber(unsigned int nb);
	void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	int shortestSpan() const;
	int longestSpan() const;
};
