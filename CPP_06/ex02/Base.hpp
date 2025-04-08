#pragma once

#include <cstdlib> // for rand(), srand()
#include <iostream>

class Base {
  public:
	virtual ~Base();
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

// class NotDerived {
//   public:
// 	virtual ~NotDerived() {}
// };

Base* generate(void);
void identify(Base* p);
void identify(Base& p);
