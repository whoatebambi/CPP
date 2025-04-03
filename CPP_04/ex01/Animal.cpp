/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florencecousergue <florencecousergue@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:29:01 by fcouserg          #+#    #+#             */
/*   Updated: 2025/02/13 15:15:05 by florencecou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("🦄 Unicorn") {
	std::cout << "Animal: Default constructor called" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal: Destructor called" << std::endl;
}

Animal::Animal(Animal const &src) : _type(src._type) {
	std::cout << "Animal: Copy constructor called" << std::endl;
}

Animal::Animal(std::string _type) : _type(_type) {
	std::cout << "Animal: Parameter constructor called" << std::endl;
}

Animal	&Animal::operator=(Animal const &rhs) {
	std::cout << "Animal: Assignment operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

std::string	Animal::getType() const {
	return (this->_type);
}

void	Animal::makeSound() const {
	std::cout << "🦄 What does a unicorn sound like?" << std::endl;
}
