/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:29:01 by fcouserg          #+#    #+#             */
/*   Updated: 2025/01/20 17:17:40 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap(); // constr. par défaut qui initialise la valeur du nombre à virgule fixe à 0
		~FragTrap(); // destructeur
		FragTrap(FragTrap const &src); // constr. de recopie
		FragTrap	&operator=(FragTrap const &rhs); // surcharge de l’opérateur d’affectation
		FragTrap(std::string name);

		void attack(const std::string& target);
		void highFivesGuys(void);
};
