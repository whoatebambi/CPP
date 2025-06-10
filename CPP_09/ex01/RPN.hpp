#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <exception>

class RPN {
    public:
        static int evaluate(const std::string& expression);
};

#endif