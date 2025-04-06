#include "C.hpp"

C::C() {
	std::cout << "C constructor called" << std::endl;
}

C::~C() {
	std::cout << "C destructor called" << std::endl;
}

C::C(const C& other) {
	std::cout << "C copy constructor called" << std::endl;
	*this = other; // Will use operator=
}

C& C::operator=(const C& rhs) {
	std::cout << "C assignment operator called" << std::endl;
	if (this == &rhs)
		return *this;
	// No members yet, but normally I'd copy them here
	(void) rhs;
	return *this;
}