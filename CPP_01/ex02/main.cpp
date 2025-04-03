/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcouserg <fcouserg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:16:51 by fcouserg          #+#    #+#             */
/*   Updated: 2024/11/24 16:55:25 by fcouserg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <iostream>

int	main(void){
	std::string brain = "HI THIS IS BRAIN";
	std::string *stringPTR = &brain;
	std::string &stringREF = brain;

	std::cout << "&brain:     " << &brain << std::endl; // L’adresse de la string en mémoire.
	std::cout << "stringPTR:  " << stringPTR << std::endl; // L’adresse stockée dans stringPTR.
	std::cout << "&stringREF: " << &stringREF << std::endl << std::endl; // L’adresse stockée dans stringREF.

	std::cout << "brain:      " << brain << std::endl; // La valeur de la string.
	std::cout << "*stringPTR: " << *stringPTR << std::endl; // La valeur pointée par stringPTR.
	std::cout << "stringREF:  " << stringREF << std::endl; // La valeur pointée par stringREF.
}
