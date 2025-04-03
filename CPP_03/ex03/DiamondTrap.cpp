/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florencecousergue <florencecousergue@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:29:01 by fcouserg          #+#    #+#             */
/*   Updated: 2025/01/21 12:58:34 by florencecou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"


/////////////////////////////////////////////////////////////////////////////////////
DiamondTrap::DiamondTrap(){
	std::cout << INVERSE << GREEN << "DiamondTrap: "
	<< BOLD << this->_name << RESET << INVERSE << GREEN 
	<< " Default constructor called" << RESET << std::endl;
}

DiamondTrap::~DiamondTrap(){
	std::cout << INVERSE << GREEN << "DiamondTrap: "
	<< BOLD << this->_name << RESET << INVERSE << GREEN 
	<< " Destructor called" << RESET << std::endl;	
}

DiamondTrap::DiamondTrap(DiamondTrap const &src) {
	std::cout << INVERSE << GREEN << "DiamondTrap: "
	<< BOLD << this->_name << RESET << INVERSE << GREEN 
	<< " Copy constructor called" << RESET << std::endl;
	*this = src;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name){
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackPoints = FragTrap::_attackPoints;
	std::cout << INVERSE << GREEN << "DiamondTrap: "
	<< BOLD << this->_name << RESET << INVERSE << GREEN 
	<< " Parameter constructor called" << RESET << std::endl;	
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap const &rhs){
	std::cout << INVERSE << GREEN << "DiamondTrap: "
	<< BOLD << this->_name << RESET << INVERSE << GREEN 
	<< " Assignment operator called" << RESET << std::endl;
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackPoints = rhs._attackPoints;
	return (*this);
}


/////////////////////////////////////////////////////////////////////////////////////
void	DiamondTrap::whoAmI(){
	std::cout << "My Diamond name is " <<  this->_name << std::endl;
	std::cout << "My ClapTrap name is " << this->ClapTrap::_name << std::endl;
}
