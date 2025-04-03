/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:29:01 by fcouserg          #+#    #+#             */
/*   Updated: 2025/01/16 20:10:44 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_nbBits = 8;


/////////////////////////////////////////////////////////////////////////////////////
Fixed::Fixed(): _nbFixed(0){
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(){
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src){
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

// constr. entier constant => en virgule fixe
Fixed::Fixed(int const intToFixed){
	// std::cout << "Int constructor called" << std::endl;
	this->_nbFixed = intToFixed * (1 << _nbBits);
}

// constr. flottant constant => virgule fixe (nb de bits de la partie fractionnaire initialisé à 8)
Fixed::Fixed(float const floatToFixed){
	// std::cout << "Float constructor called" << std::endl;
	this->_nbFixed = roundf(floatToFixed * (1 << _nbBits));
}

// surcharge de l’opérateur d’affectation
Fixed	&Fixed::operator=(Fixed const &rhs){
	// std::cout << "Copy assignment operator called" << std::endl;
	this-> _nbFixed = rhs.getRawBits();
	return (*this);
}


/////////////////////////////////////////////////////////////////////////////////////
// opérateur de comparaison : >, <, >=, <=, == et !=
bool	Fixed::operator>(Fixed const &rhs) const{
	return (this->_nbFixed > rhs._nbFixed);
}

bool	Fixed::operator<(Fixed const &rhs) const{
	return (this->_nbFixed < rhs._nbFixed);
}

bool	Fixed::operator>=(Fixed const &rhs) const{
	return (this->_nbFixed >= rhs._nbFixed);
}

bool	Fixed::operator<=(Fixed const &rhs) const{
	return (this->_nbFixed <= rhs._nbFixed);
}

bool	Fixed::operator==(Fixed const &rhs) const{
	return (this->_nbFixed == rhs._nbFixed);
}

bool	Fixed::operator!=(Fixed const &rhs) const{
	return (this->_nbFixed != rhs._nbFixed);
}


/////////////////////////////////////////////////////////////////////////////////////
// opérateurs de arithmétiques
Fixed	Fixed::operator+(Fixed const &rhs) const{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed	Fixed::operator-(Fixed const &rhs) const{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed	Fixed::operator*(Fixed const &rhs) const{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator/(Fixed const &rhs) const{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}


/////////////////////////////////////////////////////////////////////////////////////
// opérateurs d’incrémentation et de décrémentation
Fixed	&Fixed::operator++(){ // pre incr
	this->_nbFixed++;
	return (*this);
}

Fixed	&Fixed::operator--(){ // pre decr
	this->_nbFixed--;
	return (*this);
}

Fixed	Fixed::operator++(int){ // post incr
	Fixed tmp = *this;
	++*this;
	return (tmp);
}

Fixed	Fixed::operator--(int){ // post incr
	Fixed tmp = *this;
	--*this;
	return (tmp);
}


/////////////////////////////////////////////////////////////////////////////////////
Fixed		&Fixed::max(Fixed &n1, Fixed &n2){
	if (n1.getRawBits() > n2.getRawBits())
		return (n1);
	return (n2);
}

const		Fixed	&Fixed::max(const Fixed &n1, const Fixed &n2){
	if (n1.getRawBits() > n2.getRawBits())
		return (n1);
	return (n2);
}

Fixed		&Fixed::min(Fixed &n1, Fixed &n2){
	if (n1.getRawBits() < n2.getRawBits())
		return (n1);
	return (n2);
}

const Fixed	&Fixed::min(const Fixed &n1, const Fixed &n2){
	if (n1.getRawBits() < n2.getRawBits())
		return (n1);
	return (n2);
}


/////////////////////////////////////////////////////////////////////////////////////
// convertit la valeur en virgule fixe en nombre à virgule flottante
float	Fixed::toFloat(void) const{
	return static_cast<float>(this->_nbFixed) / (1 << _nbBits);
}

// convertit la valeur en virgule fixe en nombre entier
int		Fixed::toInt(void) const{
	// return (42);
	return this->_nbFixed / (1 << _nbBits);
}

int		Fixed::getRawBits() const{
	return (this->_nbFixed);
}

void	Fixed::setRawBits(int const raw){
	this->_nbFixed = raw;
}


/////////////////////////////////////////////////////////////////////////////////////
// surcharge de l’opérateur d’insertion [<<]
std::ostream &operator<<(std::ostream &o, Fixed const &rhs){
	o << rhs.toFloat();
	return (o);
}
