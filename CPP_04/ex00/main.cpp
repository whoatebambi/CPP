/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florencecousergue <florencecousergue@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:29:01 by fcouserg          #+#    #+#             */
/*   Updated: 2025/01/29 18:01:47 by florencecou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	Animal*	meta = new Animal();
	std::cout << "meta->type: " << meta->getType() << std::endl;
	const Animal*	j = new Dog();
	std::cout << "j->type: " << j->getType() << std::endl;
	const Animal*	i = new Cat();
	std::cout << "i->type: " << i->getType() << std::endl;

	meta->makeSound();
	j->makeSound();
	i->makeSound();

	WrongAnimal*	wrongmeta = new WrongAnimal();
	std::cout << "wrongmeta->type: " << wrongmeta->getType() << std::endl;
	const WrongAnimal*	h = new WrongCat();
	std::cout << "h->type: " << h->getType() << std::endl;
	wrongmeta->makeSound();
	h->makeSound();

	delete(meta);
	delete(j);
	delete(i);
	delete(wrongmeta);
	delete(h);
	return (0);
}
