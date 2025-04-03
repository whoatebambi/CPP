/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcouserg <fcouserg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:04:37 by fcouserg          #+#    #+#             */
/*   Updated: 2024/11/23 17:22:07 by fcouserg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {
}

Contact::~Contact() {
}

void	Contact::set_first_name(str first_name) {
	this->_first_name = first_name;
}

void	Contact::set_last_name(str last_name) {
	this->_last_name = last_name;
}

void	Contact::set_nickname(str nickname) {
	this->_nickname = nickname;
}

void	Contact::set_phone(str phone) {
	this->_phone = phone;
}

void	Contact::set_secret(str secret) {
	this->_secret = secret;
}

str	Contact::get_first_name() const {
	return this->_first_name;
}

str Contact::get_last_name() const {
	return this->_last_name;
}

str Contact::get_nickname() const {
	return this->_nickname;
}

str Contact::get_phone() const {
	return this->_phone;
}

str	Contact::get_secret() const {
	return this->_secret;
}
