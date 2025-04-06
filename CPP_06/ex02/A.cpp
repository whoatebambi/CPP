#include "A.hpp"

A::A() {
	std::cout << "A constructor called" << std::endl;
}

A::~A() {
	std::cout << "A destructor called" << std::endl;
}

A::A(const A& other) {
	std::cout << "A copy constructor called" << std::endl;
	*this = other; // Will use operator=
}

A& A::operator=(const A& rhs) {
	std::cout << "A assignment operator called" << std::endl;
	if (this == &rhs)
		return *this;
	// No members yet, but normally I'd copy them here
	(void) rhs;
	return *this;
}