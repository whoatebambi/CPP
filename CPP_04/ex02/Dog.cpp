/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florencecousergue <florencecousergue@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:29:01 by fcouserg          #+#    #+#             */
/*   Updated: 2025/02/13 18:02:54 by florencecou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal("🐶 Dog"), _brain(new Brain()) {
	std::cout << "🐶 Dog: Default constructor called" << std::endl;
}

Dog::~Dog() {
	std::cout << "🐶 Dog: Destructor called" << std::endl;
	delete (_brain);
}

Dog::Dog(Dog const &src) : AAnimal(src), _brain(new Brain(*src._brain)) {
    std::cout << "Dog: Copy constructor called" << std::endl;
    this->_type = src._type;
}

Dog	&Dog::operator=(Dog const &rhs){
	std::cout << "Dog: Assignment operator called" << std::endl;
	if (this != &rhs)
	{
		AAnimal::operator=(rhs);
		delete (_brain);
		this->_brain = new Brain(*rhs._brain);
	}
	return (*this);
}

void	Dog::makeSound() const {
	std::cout << "🐶 🐶🐶 🐶 🐶🐶🐶!" << std::endl;
}

std::string Dog::getIdeas(int index) const{
	// std::cout << "Dog::getIdeas" << std::endl;
    return (this->_brain->getIdeas(index));
}

void	Dog::setIdea(int index, const std::string &idea){
	// std::cout << "Dog::setIdea" << std::endl;
    this->_brain->setIdea(index, idea);
}
