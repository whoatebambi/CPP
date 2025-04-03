/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florencecousergue <florencecousergue@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:29:01 by fcouserg          #+#    #+#             */
/*   Updated: 2025/01/21 02:29:07 by florencecou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap(); // constr. par défaut qui initialise la valeur du nombre à virgule fixe à 0
		~ScavTrap(); // destructeur
		ScavTrap(ScavTrap const &src); // constr. de recopie
		ScavTrap	&operator=(ScavTrap const &rhs); // surcharge de l’opérateur d’affectation
		ScavTrap(std::string name);
		
		void guardGate();
		void attack(const std::string& target);
};
