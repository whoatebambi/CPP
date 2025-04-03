/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florencecousergue <florencecousergue@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:29:01 by fcouserg          #+#    #+#             */
/*   Updated: 2025/02/18 14:49:32 by florencecou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("DEFAULT_NAME") {
	std::cout << "Character: Default constructor called" << std::endl;
	for (int i = 0; i < _inventorySize; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const std::string &name) : _name(name) {
	// std::cout << "Character: Parameter constructor called" << std::endl;
	for (int i = 0; i < _inventorySize; i++)
		this->_inventory[i] = NULL;
}

Character::~Character() {
	// std::cout << "Character: Destructor called" << std::endl;
	for (int i = 0; i < _inventorySize; i++)
	{
		if (this->_inventory[i])
			delete (this->_inventory[i]);
	}
}

Character::Character(const Character &src) : _name(src._name) {
	// std::cout << "Character: Copy constructor called" << std::endl;
	*this = src;
}

Character	&Character::operator=(const Character &rhs) {
	std::cout << "Character: Assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		for (int i = 0; i < _inventorySize; i++)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
		}
	}
	return (*this);
}

std::string const	&Character::getName() const {
	return (this->_name);
}

void	Character::equip(AMateria* m) {
	if (m == NULL)
	{
		std::cout << "🙅 " << this->_name << " can't equip because materia is unknown" << std::endl;
		return ;
	}
	for (int i = 0; i < _inventorySize; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m->clone();
			std::cout << "💁 " << this->_name << " equipped " << m->getType() << " in slot [" << i << "]" << std::endl;
			return ;
		}
	}
	std::cout << "🙅 " << this->_name << " can't equip " << m->getType() << " because inventory is full" << std::endl;
}

void	Character::unequip(int idx) {
	if (idx >= 0 && idx < _inventorySize)
	{
		if (this->_inventory[idx])
		{
			std::cout << "🤷 " << this->_name << " unequipped " << this->_inventory[idx]->getType() << " in slot [" << idx << "]" << std::endl;
			delete (this->_inventory[idx]);
			this->_inventory[idx] = NULL;
		}
		else
			std::cout << "🙅 " << this->_name << " can't unequip because slot [" << idx << "] is empty" << std::endl;
		return ;
	}
	std::cout << "unequip() : Index is not in range" << std::endl;
}

void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < _inventorySize)
	{
		if (this->_inventory[idx])
		{
			std::cout << "🗯️  " << this->_name << " ";
			this->_inventory[idx]->use(target);
			return ;
		}
		std::cout << "🙅 " << this->_name << " can't use because slot [" << idx << "] is empty" << std::endl;
	}
	else
		std::cout << "use() : Index is not in range" << std::endl;
}
