/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florencecousergue <florencecousergue@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:29:01 by fcouserg          #+#    #+#             */
/*   Updated: 2025/01/29 18:36:57 by florencecou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("🐶 Dog") {
	// std::cout << "Dog: Default constructor called" << std::endl;
}

Dog::~Dog(){
	// std::cout << "Dog: Destructor called" << std::endl;
}

Dog::Dog(Dog const &src) : Animal(src) {
	// std::cout << "Dog: Copy constructor called" << std::endl;
	*this = src;
}

Dog	&Dog::operator=(Dog const &rhs){
	// std::cout << "Dog: Assignment operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

void	Dog::makeSound() const {
	std::cout << "🐶 🐶🐶 🐶 🐶🐶🐶!" << std::endl;
}
