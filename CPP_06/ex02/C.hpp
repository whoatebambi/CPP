#pragma once

#include "Base.hpp"

class C : public Base {
	public:
		C();
		~C();
		C(const C& other);
		C& operator=(const C& rhs);
};
