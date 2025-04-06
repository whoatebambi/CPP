#pragma once

#include "Base.hpp"

class A : public Base {
	public:
		A();
		~A();
		A(const A& other);
		A& operator=(const A& rhs);
};
