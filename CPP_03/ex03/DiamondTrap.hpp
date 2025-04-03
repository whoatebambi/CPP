/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */ 
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:29:01 by fcouserg          #+#    #+#             */
/*   Updated: 2025/01/20 16:53:55 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string _name;

	public:
		DiamondTrap(); // constr. par défaut qui initialise la valeur du nombre à virgule fixe à 0
		~DiamondTrap(); // destructeur
		DiamondTrap(DiamondTrap const &src); // constr. de recopie
		DiamondTrap	&operator=(DiamondTrap const &rhs); // surcharge de l’opérateur d’affectation
		DiamondTrap(std::string name);
		
		using ScavTrap::attack;
		void whoAmI();
};
