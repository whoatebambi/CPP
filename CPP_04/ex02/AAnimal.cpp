/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florencecousergue <florencecousergue@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:29:01 by fcouserg          #+#    #+#             */
/*   Updated: 2025/02/13 18:02:30 by florencecou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("🦄 Unicorn") {
	std::cout << "AAnimal: Default constructor called" << std::endl;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal: Destructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const &src) {
	// std::cout << "AAnimal: Copy constructor called" << std::endl;
	*this = src;
}

AAnimal::AAnimal(std::string _type) : _type(_type) {
	// std::cout << "AAnimal: Parameter constructor called" << std::endl;
}

AAnimal	&AAnimal::operator=(AAnimal const &rhs) {
	std::cout << "AAnimal: Assignment operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

std::string	AAnimal::getType() const {
	return (this->_type);
}
