/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florencecousergue <florencecousergue@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:29:01 by fcouserg          #+#    #+#             */
/*   Updated: 2025/02/18 14:43:29 by florencecou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	// std::cout << "MateriaSource: Default constructor called" << std::endl;
	for (int i = 0; i < _inventorySize; i++)
		this->_materias[i] = NULL;
}

MateriaSource::~MateriaSource() {
	// std::cout << "MateriaSource: Destructor called" << std::endl;
	for (int i = 0; i < _inventorySize; i++)
	{
		if (this->_materias[i])
		{
			delete (this->_materias[i]);
			this->_materias[i] = NULL;
		}
	}
}

MateriaSource::MateriaSource(MateriaSource const &src) {
	std::cout << "MateriaSource: Copy constructor called" << std::endl;
	*this = src;
}

MateriaSource	&MateriaSource::operator=(MateriaSource const &rhs) {
	std::cout << "MateriaSource: Assignment operator called" << std::endl;
	if (this != &rhs) 
    {
		for (int i = 0; i < 4; i++) 
		this->_materias[i] = rhs._materias[i];
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *m) {
	for (int i = 0; i < _inventorySize; i++)
	{
		if (this->_materias[i] == NULL)
		{
			std::cout << "📚 MateriaSource learned " << m->getType() << " in slot [" << i << "] ✅" << std::endl;
			this->_materias[i] = m->clone();
			delete (m);
			return ;
		}
	}
	std::cout << "📚 MateriaSource can't learn " << m->getType() << " because inventory is full" << std::endl;
	delete (m);
}

AMateria	*MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < _inventorySize; i++) 
    {
		if (this->_materias[i] && this->_materias[i]->getType() == type) 
        {
			std::cout << "📚 MateriaSource created " << this->_materias[i]->getType() << " from slot [" << i << "] ✅" << std::endl;
			// return (this->_materias[i]->clone());
			return (this->_materias[i]);
        }
	}
    std::cout << "Unknown type of Materia"<< std::endl;
	return (NULL);
}
