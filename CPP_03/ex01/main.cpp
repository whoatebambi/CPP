/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:29:01 by fcouserg          #+#    #+#             */
/*   Updated: 2025/01/20 16:48:26 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap robot1("robot1");
	ScavTrap robot2("robot2");
	robot1.attack("robot2");
	robot2.takeDamage(3);
	robot2.getInfo();
	robot2.attack("robot1");
	robot1.takeDamage(42);
	robot1.getInfo();
	robot1.attack("robot2");
	robot1.beRepaired(2);
	robot2.beRepaired(2);
	robot2.getInfo();
	robot2.guardGate();

	return (0);
}
