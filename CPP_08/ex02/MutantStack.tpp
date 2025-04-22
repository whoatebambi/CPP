#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() {
	// std::cout << "MutantStack constructor called" << std::endl;
}

template <typename T>
MutantStack<T>::~MutantStack() {
	// std::cout << "MutantStack destructor called" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other) {
	// std::cout << "MutantStack copy constructor called" << std::endl;
	*this = other;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& other) {
	// std::cout << "MutantStack assignment operator called" << std::endl;
	if (this != &other) {
		this->c = other.c;
	}
	return (*this);
}

template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::begin() {
	return this->c.begin();
}

template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::end() {
	return this->c.end();
}

template <typename T>
typename std::stack<T>::container_type::const_iterator MutantStack<T>::begin() const {
	return this->c.begin();
}

template <typename T>
typename std::stack<T>::container_type::const_iterator MutantStack<T>::end() const {
	return this->c.end();
}

template <typename T>
typename std::stack<T>::container_type::reverse_iterator MutantStack<T>::rbegin() {
	return this->c.begin();
}

template <typename T>
typename std::stack<T>::container_type::reverse_iterator MutantStack<T>::rend() {
	return this->c.end();
}

template <typename T>
typename std::stack<T>::container_type::const_reverse_iterator MutantStack<T>::rbegin() const {
	return this->c.begin();
}

template <typename T>
typename std::stack<T>::container_type::const_reverse_iterator MutantStack<T>::rend() const {
	return this->c.end();
}