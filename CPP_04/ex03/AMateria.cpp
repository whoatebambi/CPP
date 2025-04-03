/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florencecousergue <florencecousergue@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:29:01 by fcouserg          #+#    #+#             */
/*   Updated: 2025/02/18 14:10:19 by florencecou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("default materia") {
	// std::cout << "AMateria: Default constructor called" << std::endl;
}

AMateria::~AMateria() {
	// std::cout << "AMateria: Destructor called" << std::endl;
}

AMateria::AMateria(AMateria const &src) {
	// std::cout << "AMateria: Copy constructor called" << std::endl;
	*this = src;
}

AMateria	&AMateria::operator=(AMateria const &rhs) {
	// std::cout << "AMateria: Assignment operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

AMateria::AMateria(std::string const & type) : _type(type) {
	// std::cout << "AMateria: Parameter constructor called" << std::endl;
}

std::string const &AMateria::getType() const {
	return (this->_type);
}

void AMateria::use(ICharacter &target) {
	
    std::cout << "* uses a Materia on " << target.getName() << " *" << std::endl;
}
