#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <exception>

class RPN {
	private:
		RPN(const RPN& other);
		RPN&	operator=(const RPN& other);

	public:
		RPN();
		~RPN();
		static int parseInput(const std::string& expression);
};

#endif