/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:29:01 by fcouserg          #+#    #+#             */
/*   Updated: 2025/01/20 16:55:18 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


/////////////////////////////////////////////////////////////////////////////////////
ScavTrap::ScavTrap(){
	std::cout << INVERSE << MAGENTA << "ScavTrap: " 
	<< BOLD << this->_name << RESET << INVERSE << MAGENTA 
	<< " Default constructor called" << RESET << std::endl;
}

ScavTrap::~ScavTrap(){
	std::cout << INVERSE << MAGENTA << "ScavTrap: "
	<< BOLD << this->_name << RESET << INVERSE << MAGENTA 
	<< " Destructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src){
	std::cout << INVERSE << MAGENTA << "ScavTrap: "
	<< BOLD << this->_name << RESET << INVERSE << MAGENTA 
	<< " Copy constructor called" << RESET << std::endl;
	*this = src;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
	std::cout << INVERSE << MAGENTA << "ScavTrap: "
	<< BOLD << this->_name << RESET << INVERSE << MAGENTA 
	<< " Parameter constructor called" << RESET << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackPoints = 20;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &rhs){
	std::cout << INVERSE << MAGENTA << "ScavTrap: "
	<< BOLD << this->_name << RESET << INVERSE << MAGENTA 
	<< " Assignment operator called" << RESET << std::endl;
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackPoints = rhs._attackPoints;
	return (*this);
}


/////////////////////////////////////////////////////////////////////////////////////
void ScavTrap::attack(const std::string& target){
	if (this->_hitPoints <= 0)
	{
		std::cout << "ScavTrap " << RED << "💀 " << BOLD << UNDERLINE << this->_name << RESET << RED
		<< " is already dead and can't take more damage." << RESET << std::endl << std::endl;
		return ;
	}
	if (this->_energyPoints <= 0)
	{
		std::cout << "ScavTrap " << BLUE << BOLD << UNDERLINE << this->_name << RESET 
		<< " is too exhausted to attack." << RESET << std::endl << std::endl;
		return ;
	}
	this->_energyPoints--;
	std::cout << "ScavTrap " << BOLD << UNDERLINE << BLUE << this->_name << RESET
	<< " attacks " << BOLD << UNDERLINE << RED << target << RESET << "." << std::endl << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "🛡️ ScavTrap "<< BLUE  << BOLD << UNDERLINE << this->_name << RESET
		<< " is now in gate keeper mode." << RESET << std::endl << std::endl;
}
