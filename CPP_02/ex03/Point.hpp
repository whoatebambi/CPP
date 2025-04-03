/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:29:01 by fcouserg          #+#    #+#             */
/*   Updated: 2025/01/16 20:12:30 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed 	_x;
		const Fixed 	_y;

	public:
		Point(); // constr. par défaut qui initialise x et y à 0
		Point(float const n1, float const n2); // constructeur prenant deux flottants constants en paramètres et initialisant x et y avec ces derniers.
		Point(Point const &src); // constr. de recopie
		Point	&operator=(Point const &rhs); // surcharge de l’opérateur d’affectation
		~Point(); // destructeur

		const Fixed &getX(void) const;
		const Fixed &getY(void) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
std::ostream	&operator<<(std::ostream &o, Point const point);
