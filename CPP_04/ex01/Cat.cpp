/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florencecousergue <florencecousergue@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:29:01 by fcouserg          #+#    #+#             */
/*   Updated: 2025/02/13 15:31:28 by florencecou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("🐱 Cat"), _brain(new Brain()) {
	std::cout << "🐱 Cat: Default constructor called" << std::endl;
}

Cat::~Cat() {
	std::cout << "🐱 Cat: Destructor called" << std::endl;
	delete (_brain);
}

Cat::Cat(Cat const &src) : Animal(src), _brain(new Brain(*src._brain)) {
    std::cout << "Cat: Copy constructor called" << std::endl;
    this->_type = src._type;
}

Cat	&Cat::operator=(Cat const &rhs){
	std::cout << "Cat: Assignment operator called" << std::endl;
	if (this != &rhs)
	{
		Animal::operator=(rhs);
        delete (_brain);
        this->_brain = new Brain(*rhs._brain); // deep copy to avoid double free during destruction and shared memory address of brain
    }
	return (*this);
}

void	Cat::makeSound() const {
	std::cout << "🐱🐱 🐱 🐱!" << std::endl;
}

std::string Cat::getIdeas(int index) const{
	// std::cout << "Cat::getIdeas" << std::endl;
    return (this->_brain->getIdeas(index));
}

void	Cat::setIdea(int index, const std::string &idea){
	// std::cout << "Cat::setIdea" << std::endl;
    this->_brain->setIdea(index, idea);
}
