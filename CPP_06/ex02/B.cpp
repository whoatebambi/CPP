#include "B.hpp"

B::B() {
	std::cout << "B constructor called" << std::endl;
}

B::~B() {
	std::cout << "B destructor called" << std::endl;
}

B::B(const B& other) {
	std::cout << "B copy constructor called" << std::endl;
	*this = other; // Will use operator=
}

B& B::operator=(const B& rhs) {
	std::cout << "B assignment operator called" << std::endl;
	if (this == &rhs)
		return *this;
	// No members yet, but normally I'd copy them here
	(void) rhs;
	return *this;
}