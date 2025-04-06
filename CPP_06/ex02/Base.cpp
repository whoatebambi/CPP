#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {
	std::cout << "Base destructor called" << std::endl;
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
	if (dynamic_cast<A*>(p))
		std::cout << "Object is of type A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Object is of type B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Object is of type C" << std::endl;
	else
		std::cout << "Type Unknown" << std::endl;
}

// Prints the actual type of the object referenced by p: "A", "B", or "C".
// Using a pointer inside this function is forbidden.
void identify(Base& p) {
	try {
		(void) dynamic_cast<A&>(p);
		std::cout << "Object if of type A" << std::endl;
		return;
	} catch (const std::exception& e) {
	}

	try {
		(void) dynamic_cast<B&>(p);
		std::cout << "Object if of type B" << std::endl;
		return;
	} catch (const std::exception& e) {
	}

	try {
		(void) dynamic_cast<C&>(p);
		std::cout << "Object if of type C" << std::endl;
		return;
	} catch (const std::exception& e) {
	}
	std::cout << "Unknown type" << std::endl;
}
