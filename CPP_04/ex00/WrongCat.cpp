/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florencecousergue <florencecousergue@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:29:01 by fcouserg          #+#    #+#             */
/*   Updated: 2025/01/29 18:37:05 by florencecou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("🐵 WrongCat") {
	// std::cout << "WrongCat: Default constructor called" << std::endl;
}

WrongCat::~WrongCat() {
	// std::cout << "WrongCat: Destructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &src) : WrongAnimal(src) {
	// std::cout << "WrongCat: Copy constructor called" << std::endl;
	*this = src;
}

WrongCat	&WrongCat::operator=(WrongCat const &rhs){
	// std::cout << "WrongCat: Assignment operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

void	WrongCat::makeSound() const {
	std::cout << "🐵 🐵🐵 🐵!" << std::endl;
}
