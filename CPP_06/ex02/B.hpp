#pragma once

#include "Base.hpp"

class B : public Base {
	public:
		B();
		~B();
		B(const B& other);
		B& operator=(const B& rhs);
};
