/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florencecousergue <florencecousergue@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:29:01 by fcouserg          #+#    #+#             */
/*   Updated: 2025/02/18 14:10:30 by florencecou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("🧊 ice") {
	// std::cout << "Ice: Default constructor called" << std::endl;
}

Ice::~Ice() {
	// std::cout << "Ice: Destructor called" << std::endl;
}

Ice::Ice(Ice const &src) : AMateria(src) {
	// std::cout << "Ice: Copy constructor called" << std::endl;
}

Ice	&Ice::operator=(Ice const &rhs) {
	std::cout << "Ice: Assignment operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

Ice::Ice(std::string const & type) {
	std::cout << "Ice: Parameter constructor called" << std::endl;
	this->_type = type;
}

std::string const &Ice::getType() const {
	return (this->_type);
}

AMateria* Ice::clone() const {
	// std::cout << "Ice::clone() called" << std::endl;
	return (new Ice(*this));
}

void Ice::use(ICharacter &target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
