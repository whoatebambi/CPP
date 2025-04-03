/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:29:01 by fcouserg          #+#    #+#             */
/*   Updated: 2025/01/20 17:00:06 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


/////////////////////////////////////////////////////////////////////////////////////
ClapTrap::ClapTrap(){
	// std::cout << "Default constructor called" << std::endl;
}

ClapTrap::~ClapTrap(){
	// std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src){
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackPoints(0){
	// std::cout << "Parameter constructor called" << std::endl;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &rhs){
	// std::cout << "Assignment operator called" << std::endl;
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackPoints = rhs._attackPoints;
	return (*this);
}


/////////////////////////////////////////////////////////////////////////////////////
void ClapTrap::attack(const std::string& target){
	if (this->_hitPoints <= 0)
	{
		std::cout << RED << "💀 ClapTrap " << BOLD << UNDERLINE << this->_name << RESET << RED
		<< " is already dead and can't attack." << RESET << std::endl << std::endl;
		return ;
	}
	if (this->_energyPoints <= 0)
	{
		std::cout  << "ClapTrap " << GREEN << BOLD << UNDERLINE << this->_name << RESET 
		<< " is too exhausted to attack." << RESET << std::endl << std::endl;
		return ;
	}
	this->_energyPoints--;
	std::cout << "ClapTrap " << BOLD << UNDERLINE << GREEN << this->_name << RESET
	<< " attacks " << BOLD << UNDERLINE << RED << target << RESET << "." << std::endl << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
	if (this->_hitPoints <= 0)
	{
		std::cout << RED << "💀 ClapTrap " << BOLD << UNDERLINE << this->_name << RESET << RED
		<< " is already dead and can't take more damage." << RESET << std::endl << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << BOLD << UNDERLINE << GREEN << this->_name << RESET << " took "
	<< BOLD << amount << RESET << " damage points." << std::endl << std::endl;
	this->_hitPoints -= amount;
	if (this->_hitPoints <= 0)
	{
		std::cout << RED << "💀 ClapTrap " << BOLD << UNDERLINE << this->_name << RESET << RED
		<< " died." << RESET << std::endl << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount){
	if (this->_energyPoints <= 0)
	{
		std::cout  << "ClapTrap " << GREEN << BOLD << UNDERLINE << this->_name << RESET
		<< " is too exhausted to be repaired." << RESET << std::endl << std::endl;
		return ;
	}
	if (this->_hitPoints <= 0)
	{
		std::cout << RED << "💀 ClapTrap " << BOLD << UNDERLINE << this->_name << RESET << RED
		<< " is already dead and can't be repaired." << RESET << std::endl << std::endl;
		return ;
	}	
	std::cout << "ClapTrap " << BOLD << UNDERLINE << GREEN << this->_name << RESET << " has repaired itself and gained "
	<< BOLD << amount << RESET << " hit points." << std::endl << std::endl;
	this->_energyPoints--;
	this->_hitPoints += amount;
}

void	ClapTrap::getInfo(){
	if (this->_hitPoints <= 0)
		std::cout << RED << "💀 ClapTrap " << BOLD << UNDERLINE << this->_name << RESET << RED
		<< " has:" << RESET << std::endl;
	else
		std::cout << "ClapTrap " << BOLD << UNDERLINE << GREEN << this->_name << RESET << " has:" << std::endl;
	std::cout << "- " << BOLD << this->_hitPoints << RESET << " Hit points left." << std::endl;
	std::cout << "- " << BOLD << this->_energyPoints << RESET << " Energy points left." << std::endl;
	std::cout << "- " << BOLD << this->_attackPoints << RESET << " Attack damage." << std::endl << std::endl;
}
