#include "Serializer.hpp"

Serializer::Serializer() {
	std::cout << "Serializer constructor called" << std::endl;
}

Serializer::~Serializer() {
	std::cout << "Serializer destructor called" << std::endl;
}

Serializer::Serializer(const Serializer& other) {
	std::cout << "Serializer copy constructor called" << std::endl;
	*this = other; // Will use operator=
}

Serializer& Serializer::operator=(const Serializer& rhs) {
	std::cout << "Serializer assignment operator called" << std::endl;
	if (this == &rhs)
		return *this;
	static_cast<void>(rhs);
	return *this;
}

// Takes a pointer and converts it to the unsigned integer type uintptr_t.
uintptr_t Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

// Takes an unsigned integer parameter and converts it to a pointer to Data.
Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}
