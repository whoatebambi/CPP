/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:29:01 by fcouserg          #+#    #+#             */
/*   Updated: 2025/01/20 17:19:37 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	FragTrap robot1("robot1");
	ScavTrap robot2("robot2");
	robot1.attack("robot2");
	robot2.takeDamage(3);
	robot2.getInfo();
	robot2.attack("robot1");
	robot1.takeDamage(420);
	robot1.getInfo();
	robot1.attack("robot2");
	robot1.beRepaired(2);
	robot2.beRepaired(2);
	robot2.getInfo();
	robot2.guardGate();
	robot1.highFivesGuys();

	return (0);
}
