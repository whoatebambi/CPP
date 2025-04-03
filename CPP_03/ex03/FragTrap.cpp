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

#include "FragTrap.hpp"


/////////////////////////////////////////////////////////////////////////////////////
FragTrap::FragTrap(){
	std::cout << INVERSE << RED << "FragTrap: " 
	<< BOLD << this->_name << RESET << INVERSE << RED 
	<< " Default constructor called" << RESET << std::endl;
}

FragTrap::~FragTrap(){
	std::cout << INVERSE << RED << "FragTrap: "
	<< BOLD << this->_name << RESET << INVERSE << RED 
	<< " Destructor called" << RESET << std::endl;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src){
	std::cout << INVERSE << RED << "FragTrap: "
	<< BOLD << this->_name << RESET << INVERSE << RED 
	<< " Copy constructor called" << RESET << std::endl;
	*this = src;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name){
	std::cout << INVERSE << RED << "FragTrap: "
	<< BOLD << this->_name << RESET << INVERSE << RED 
	<< " Parameter constructor called" << RESET << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackPoints = 30;
}

FragTrap	&FragTrap::operator=(FragTrap const &rhs){
	std::cout << INVERSE << RED << "FragTrap: "
	<< BOLD << this->_name << RESET << INVERSE << RED 
	<< " Assignment operator called" << RESET << std::endl;
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackPoints = rhs._attackPoints;
	return (*this);
}


/////////////////////////////////////////////////////////////////////////////////////
void FragTrap::attack(const std::string& target){
	if (this->_hitPoints <= 0)
	{
		std::cout << "FragTrap " << RED << "💀 " << BOLD << UNDERLINE << this->_name << RESET << RED
		<< " is already dead and can't take more damage." << RESET << std::endl << std::endl;
		return ;
	}
	if (this->_energyPoints <= 0)
	{
		std::cout << "FragTrap " << BLUE << BOLD << UNDERLINE << this->_name << RESET 
		<< " is too exhausted to attack." << RESET << std::endl << std::endl;
		return ;
	}
	this->_energyPoints--;
	std::cout << "FragTrap " << BOLD << UNDERLINE << BLUE << this->_name << RESET
	<< " attacks " << BOLD << UNDERLINE << RED << target << RESET << "." << std::endl << std::endl;
}

void	FragTrap::highFivesGuys(void){
	std::cout << "✋ FragTrap "<< BLUE  << BOLD << UNDERLINE << this->_name << RESET
	<< " is asking for a high fives!" << RESET << std::endl << std::endl;
}
