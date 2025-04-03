/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:29:01 by fcouserg          #+#    #+#             */
/*   Updated: 2025/01/16 20:12:07 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): _x(0), _y(0){
	// std::cout << "Default constructor called" << std::endl;
}

Point::Point(const Point &src) : _x(src.getX()), _y(src.getY()){
	// std::cout << "Copy constructor called" << std::endl;
}

Point::Point(const float x, const float y) : _x(x), _y(y){
	// std::cout << "Point(): _x(" << x << "), _y(" << y << ")" << std::endl;
}

Point::~Point(){
	// std::cout << "Destructor called" << std::endl;
}

const Fixed &Point::getX(void) const{
	return this->_x;
}

const Fixed &Point::getY(void) const{
	return this->_y;
}

std::ostream	&operator<<(std::ostream &o, Point const point){
	o << "Point (" << point.getX() << ", " << point.getY() << ")";
	return (o);
}
