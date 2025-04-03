/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florencecousergue <florencecousergue@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:29:01 by fcouserg          #+#    #+#             */
/*   Updated: 2025/01/29 18:39:41 by florencecou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("🐱 Cat") {
	// std::cout << "Cat: Default constructor called" << std::endl;
}

Cat::~Cat() {
	// std::cout << "Cat: Destructor called" << std::endl;
}

Cat::Cat(Cat const &src) : Animal(src) {
	// std::cout << "Cat: Copy constructor called" << std::endl;
    *this = src;
}

Cat	&Cat::operator=(Cat const &rhs){
	// std::cout << "Cat: Assignment operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

void	Cat::makeSound() const {
	std::cout << "🐱🐱 🐱 🐱!" << std::endl;
}

