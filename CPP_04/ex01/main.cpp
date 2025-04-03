/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florencecousergue <florencecousergue@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:29:01 by fcouserg          #+#    #+#             */
/*   Updated: 2025/02/13 17:52:04 by florencecou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main(void)
{
    // Dog basic;
    // Dog tmp = basic;

    // Dog basic2;
    // Dog tmp2;
    // tmp2 = basic2;

	int nb = 4;
	Animal *farm[nb];
	for (int i = 0; i < nb; i++)
	{
		if (i % 2)
			farm[i] = new Dog();
		else
			farm[i] = new Cat();
		farm[i]->makeSound();
	}
	for (int i = 0; i < nb; i++)
		delete (farm[i]);

	// Cat *heap_cat = new Cat();
	// std::cout << "heap_cat->idea[0] = " << heap_cat->getIdeas(0) << std::endl;
	// heap_cat->setIdea(0, "I am a cat");
	// std::cout << "heap_cat->idea[0] = " << heap_cat->getIdeas(0) << std::endl;

	// Cat *copy = new Cat();
	// heap_cat->setIdea(0, "I am a cat too!");
	// *copy = *heap_cat;
	// std::cout << "copy->idea[0] = " << copy->getIdeas(0) << std::endl;
	// delete (copy);
	// delete (heap_cat);

	return (0);
}
