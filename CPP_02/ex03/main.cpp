/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:29:01 by fcouserg          #+#    #+#             */
/*   Updated: 2025/01/16 18:56:16 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main( void )
{
	// INSIDE
	Point a1(1, 1);
	Point b1(3, 7);
	Point c1(9, 2);
	Point p1(4, 4);
	if (bsp(a1, b1, c1, p1))
		std::cout << p1 << " is inside the triangle" << std::endl;
	else
		std::cout << p1 << " is not inside the triangle" << std::endl;

	// OUTSIDE
	Point a2(1, 1);
	Point b2(2, 3);
	Point c2(4, 2);
	Point p2(21, 14);
	if (bsp(a2, b2, c2, p2))
		std::cout << p2 << " is inside the triangle" << std::endl;
	else
		std::cout << p2 << " is not inside the triangle" << std::endl;

	return (0);
}
