/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florencecousergue <florencecousergue@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:29:01 by fcouserg          #+#    #+#             */
/*   Updated: 2025/02/18 14:52:00 by florencecou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int	main(void)
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("🧊 ice");
	me->equip(tmp);
	tmp = src->createMateria("🫀 Cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	// AMateria *ice1 = new Ice();
	// AMateria *cure1 = new Cure();
	// std::cout << "cure1->_type = " << cure1->getType() << std::endl;
	// Character *human1 = new Character("Marc");
	// human1->equip(ice1);
	// human1->equip(cure1);
	// Character *human2 = new Character("Jean");
	// human1->use(0, *human2);
	// human1->equip(ice1);
	// human1->equip(ice1);
	// human1->equip(ice1);
	// // inventory full
	// human1->equip(ice1);
	// delete (human1);
	// delete (human2);

	return (0);
}
