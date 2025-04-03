/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:29:01 by fcouserg          #+#    #+#             */
/*   Updated: 2025/01/20 16:59:46 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


/////////////////////////////////////////////////////////////////////////////////////
ClapTrap::ClapTrap(){
	std::cout << INVERSE << BLUE << "ClapTrap: " 
	<< BOLD << this->_name << RESET << INVERSE << BLUE 
	<< " Default constructor called" << RESET << std::endl;
}

ClapTrap::~ClapTrap(){
	std::cout << INVERSE << BLUE << "ClapTrap: "
	<< BOLD << this->_name << RESET << INVERSE << BLUE 
	<< " Destructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src){
	std::cout << INVERSE << BLUE << "ClapTrap: "
	<< BOLD << this->_name << RESET << INVERSE << BLUE 
	<< " Copy constructor called" << RESET << std::endl;
	*this = src;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackPoints(0){
	std::cout << INVERSE << BLUE << "ClapTrap: "
	<< BOLD << this->_name << RESET << INVERSE << BLUE 
	<< " Parameter constructor called" << RESET << std::endl;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &rhs){
	std::cout << INVERSE << BLUE << "ClapTrap: "
	<< BOLD << this->_name << RESET << INVERSE << BLUE 
	<< " Assignment operator called" << RESET << std::endl;
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
		std::cout << "ClapTrap " << BLUE << BOLD << UNDERLINE << this->_name << RESET 
		<< " is too exhausted to attack." << RESET << std::endl << std::endl;
		return ;
	}
	this->_energyPoints--;
	std::cout << "ClapTrap " << BOLD << UNDERLINE << BLUE << this->_name << RESET
	<< " attacks " << BOLD << UNDERLINE << RED << target << RESET << "." << std::endl << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
	if (this->_hitPoints <= 0)
	{
		std::cout << "💀 " << RED << BOLD << UNDERLINE << this->_name << RESET << RED
		<< " is already dead and can't take more damage." << RESET << std::endl << std::endl;
		return ;
	}
	std::cout << BOLD << UNDERLINE << BLUE << this->_name << RESET << " took "
	<< BOLD << amount << RESET << " damage points." << std::endl << std::endl;
	this->_hitPoints -= amount;
	if (this->_hitPoints <= 0)
	{
		std::cout << RED << "💀 " << BOLD << UNDERLINE << this->_name << RESET << RED
		<< " died." << RESET << std::endl << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount){
	if (this->_energyPoints <= 0)
	{
		std::cout << BLUE << BOLD << UNDERLINE << this->_name << RESET
		<< " is too exhausted to be repaired." << RESET << std::endl << std::endl;
		return ;
	}
	if (this->_hitPoints <= 0)
	{
		std::cout << RED << BOLD << UNDERLINE << this->_name << RESET << RED
		<< " is already dead and can't be repaired." << RESET << std::endl << std::endl;
		return ;
	}	
	std::cout << BOLD << UNDERLINE << BLUE << this->_name << RESET << " has repaired itself and gained "
	<< BOLD << amount << RESET << " hit points." << std::endl << std::endl;
	this->_energyPoints--;
	this->_hitPoints += amount;
}

void	ClapTrap::getInfo(){
	if (this->_hitPoints <= 0)
		std::cout << RED << "💀 " << BOLD << UNDERLINE << this->_name << RESET << RED
		<< " has:" << RESET << std::endl;
	else
		std::cout << BOLD << UNDERLINE << BLUE << this->_name << RESET << " has:" << std::endl;
	std::cout << "- " << BOLD << this->_hitPoints << RESET << " Hit points left." << std::endl;
	std::cout << "- " << BOLD << this->_energyPoints << RESET << " Energy points left." << std::endl;
	std::cout << "- " << BOLD << this->_attackPoints << RESET << " Attack damage." << std::endl << std::endl;
}
