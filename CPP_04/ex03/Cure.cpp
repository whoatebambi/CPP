/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florencecousergue <florencecousergue@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:29:01 by fcouserg          #+#    #+#             */
/*   Updated: 2025/02/18 14:10:34 by florencecou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("🫀 Cure") {
	// std::cout << "Cure: Default constructor called" << std::endl;
}

Cure::~Cure() {
	// std::cout << "Cure: Destructor called" << std::endl;
}

Cure::Cure(Cure const &src) : AMateria(src) {
	// std::cout << "Cure: Copy constructor called" << std::endl;
}

Cure	&Cure::operator=(Cure const &rhs) {
	std::cout << "Cure: Assignment operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

Cure::Cure(std::string const & type) {
	std::cout << "Cure: Parameter constructor called" << std::endl;
	this->_type = type;
}

std::string const &Cure::getType() const {
	return (this->_type);
}

AMateria* Cure::clone() const {
	// std::cout << "Cure::clone() called" << std::endl;
	return (new Cure(*this));
}

void Cure::use(ICharacter &target) {
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
