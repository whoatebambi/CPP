#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

template <typename T> MutantStack<T>::MutantStack() {
	std::cout << "MutantStack constructor called" << std::endl;
}

template <typename T> MutantStack<T>::~MutantStack() {
	std::cout << "MutantStack destructor called" << std::endl;
}

template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::begin() {
	return this->c.begin();
}

template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::end() {
	return this->c.end();
}


#endif