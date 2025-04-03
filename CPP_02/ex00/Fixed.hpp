/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:29:01 by fcouserg          #+#    #+#             */
/*   Updated: 2025/01/16 19:07:35 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Fixed
{
	private:
		int					_nbFixed; // entier pour stocker la valeur du nombre en virgule fixe
		static const int	_nbBits; // entier constant statique pour stocker le nombre de bits de la partie

	public:
		Fixed(); // constructeur par défaut qui initialise la valeur du nombre à virgule fixe à 0
		~Fixed(); // destructeur
		Fixed(Fixed const &src); // constructeur de recopie
		Fixed	&operator=(Fixed const &rhs); // surcharge de l’opérateur d’affectation
		int		getRawBits(void) const; // retourne la valeur du nombre à virgule fixe sans la convertir
		void	setRawBits(int const raw); // initialise la valeur du nombre à virgule fixe avec celle passée en paramètre
};
