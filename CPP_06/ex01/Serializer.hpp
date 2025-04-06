#pragma once

#include <cctype>
#include <cerrno>
#include <iomanip>
#include <iostream>
#include <string>
// <stdint.h>

struct Data {
	int number;
	std::string text;
};

class Serializer {
  private:
  public:
	Serializer();
	~Serializer();
	Serializer(const Serializer& other);
	Serializer& operator=(const Serializer& rhs);

	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};
