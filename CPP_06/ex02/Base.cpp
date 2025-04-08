#include "Base.hpp"

Base::~Base() {
	// std::cout << "Base destructor called" << std::endl;
}

// Randomly instantiates A, B, or C and returns the instance as a Base pointer.
Base* generate(void) {
	int random = std::rand() % 3;
	switch (random) {
	case 0:
		return new A();
	case 1:
		return new B();
	case 2:
		return new C();
	}
	return NULL;
}

// Prints the actual type of the object pointed to by p: "A", "B", or "C".
void identify(Base* p) {
	// returns nullptr if cast fails
	if (dynamic_cast<A*>(p))
		std::cout << "Pointer object is of type A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Pointer object is of type B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Pointer object is of type C" << std::endl;
	else
		std::cout << "Pointer object: Type Unknown" << std::endl;
}

// Prints the actual type of the object referenced by p: "A", "B", or "C".
// Using a pointer inside this function is forbidden.
void identify(Base& p) {
	// throws std::bad_cast if cast fails
	try {
		(void) dynamic_cast<A&>(p);
		std::cout << "Reference object is of type A" << std::endl;
		return;
	} catch (const std::bad_cast& e) {
		// std::cout << "Bad cast: " << e.what() << std::endl;
	}

	try {
		(void) dynamic_cast<B&>(p);
		std::cout << "Reference object is of type B" << std::endl;
		return;
	} catch (const std::bad_cast& e) {
		// std::cout << "Bad cast: " << e.what() << std::endl;
	}

	try {
		(void) dynamic_cast<C&>(p);
		std::cout << "Reference object is of type C" << std::endl;
		return;
	} catch (const std::bad_cast& e) {
		// std::cout << "Bad cast: " << e.what() << std::endl;
	}

	std::cout << "Reference object: Type unknown" << std::endl;
}
