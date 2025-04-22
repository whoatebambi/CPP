#include "Span.hpp"

Span::Span() {
	// std::cout << "Span constructor called" << std::endl;
}

Span::Span(unsigned int N) : _maxSize(N) {
	// std::cout << "Span parameter constructor called" << std::endl;
}

Span::~Span() {
	// std::cout << "Span destructor called" << std::endl;
}

Span::Span(const Span& other) : _data(other._data), _maxSize(other._maxSize) {
	std::cout << "Span copy constructor called" << std::endl;
}

Span& Span::operator=(const Span& other) {
	std::cout << "Span assignment operator called" << std::endl;
	if (this != &other) {
		this->_maxSize = other._maxSize;
		this->_data = other._data;
	}
	return (*this);
}

int& Span::operator[](unsigned int index) {
	if (index >= this->_maxSize)
		throw std::runtime_error("Index is out of range");
	return _data[index];
}

void Span::addNumber(unsigned int nb) {
	if (_data.size() >= this->_maxSize)
		throw std::runtime_error("Span is full");
	this->_data.push_back(nb);
}

int Span::shortestSpan() const {
	if (_data.size() <= 1)
		throw std::runtime_error("Span is empty or contains only 1 element");

	// O(n log n)
	std::vector<int> copyVec = _data;
	std::sort(copyVec.begin(), copyVec.end());
	int shortest = std::abs(copyVec[1] - copyVec[0]);
	for (size_t i = 0; i < copyVec.size() - 1; ++i) {
		int tmp = abs(copyVec[i] - copyVec[i + 1]);
		if (tmp < shortest)
			shortest = tmp;
	}

	return shortest;
}

int Span::longestSpan() const {
	if (_data.size() <= 1)
		throw std::runtime_error("Span is empty or contains only 1 element");

	// O(n) + O(n) = O(n)
	std::vector<int>::const_iterator min = std::min_element(_data.begin(), _data.end());
	std::vector<int>::const_iterator max = std::max_element(_data.begin(), _data.end());

	return *max - *min;
}
