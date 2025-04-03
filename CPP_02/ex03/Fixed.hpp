/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:29:01 by fcouserg          #+#    #+#             */
/*   Updated: 2025/01/16 20:11:53 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

class Fixed
{
	private:
		int					_nbFixed; // entier pour stocker la valeur du nombre en virgule fixe
		int const static	_nbBits; // entier constant statique pour stocker le nombre de bits de la partie

	public:
		Fixed(); // constr. par défaut qui initialise la valeur du nombre à virgule fixe à 0
		~Fixed(); // destructeur
		Fixed(Fixed const &src); // constr. de recopie
		Fixed(int const intToFixed);// constr. entier constant => en virgule fixe
		Fixed(float const floatToFixed); // constr. flottant constant => virgule fixe (nb de bits de la partie fractionnaire initialisé à 8)
		Fixed	&operator=(Fixed const &rhs); // surcharge de l’opérateur d’affectation

		// opérateur de comparaison
		bool	operator>(Fixed const &rhs) const;
		bool	operator<(Fixed const &rhs) const;
		bool	operator>=(Fixed const &rhs) const;
		bool	operator<=(Fixed const &rhs) const;
		bool	operator==(Fixed const &rhs) const;
		bool	operator!=(Fixed const &rhs) const;

		// opérateurs de arithmétiques
		Fixed	operator+(Fixed const &rhs) const;
		Fixed	operator-(Fixed const &rhs) const;
		Fixed	operator*(Fixed const &rhs) const;
		Fixed	operator/(Fixed const &rhs) const;

		// opérateurs d’incrémentation et de décrémentation
		Fixed	&operator++(); //pre incr
		Fixed	&operator--(); //pre decr
		Fixed	operator++(int); //post incr
		Fixed	operator--(int); //post decr

		static Fixed		&max(Fixed &n1, Fixed &n2);
		static const Fixed	&max(const Fixed &n1, const Fixed &n2);
		static Fixed		&min(Fixed &n1, Fixed &n2);
		static const Fixed	&min(const Fixed &n1, const Fixed &n2);

		int		getRawBits(void) const; // retourne la valeur du nombre à virgule fixe sans la convertir
		void	setRawBits(int const raw); // initialise la valeur du nombre à virgule fixe avec celle passée en paramètre
		float	toFloat(void) const; // convertit la valeur en virgule fixe en nombre à virgule flottante
		int		toInt(void) const; // convertit la valeur en virgule fixe en nombre entier
};

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs);
// surcharge de l’opérateur d’insertion [<<] qui insère une représentation en virgule flottante
// du nombre à virgule fixe dans le flux de sortie (objet output stream) passé en paramètre
