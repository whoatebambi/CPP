#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>


template <typename T> class MutantStack : public std::stack<T> {
	public:
		MutantStack();
		~MutantStack();

		// Create a type alias iterator that corresponds to the iterator type of the
		// container used internally by std::stack<T> (which is usually a std::deque<T>)
		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin();
		iterator end();
};

#endif

#include "MutantStack.tpp"