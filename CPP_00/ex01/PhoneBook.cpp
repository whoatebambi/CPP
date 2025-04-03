/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcouserg <fcouserg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:04:37 by fcouserg          #+#    #+#             */
/*   Updated: 2024/11/23 17:23:41 by fcouserg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	this->_index = 0;
	this->_total = 0;
}

PhoneBook::~PhoneBook() {}

void PhoneBook::add_contact_info(const std::string& prompt, std::string& field) {
    while (true) {
        std::cout << BOLD << GREEN << prompt << RESET;
        std::cin.clear();

        if (!std::getline(std::cin >> std::ws, field)) {
            std::cout << BOLD << RED << "Input error. Please try again." << RESET << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        if (field.empty()) {
            std::cout << BOLD << RED << "Input can't be empty." << RESET << std::endl;
            continue;
        }
        break;
    }
}

void	PhoneBook::add_contact(){
	str	first_name;
	str	last_name;
	str	nickname;
	str	phone;
	str	secret;

	system("clear");
	if (this->_index == 8)
		this->_index = 0;
	
	add_contact_info("Enter First Name: ", first_name);
    this->_array[this->_index].set_first_name(first_name);

    add_contact_info("Enter Last Name: ", last_name);
    this->_array[this->_index].set_last_name(last_name);

    add_contact_info("Enter Nickname: ", nickname);
    this->_array[this->_index].set_nickname(nickname);

	add_contact_info("Enter Phone number: ", phone);
    this->_array[this->_index].set_phone(phone);

	add_contact_info("Enter Darkest secret: ", secret);
    this->_array[this->_index].set_secret(secret);

	this->_index++;
	if (_total < 8)
		_total++;
}

void	PhoneBook::search_contact() {
	int	i = 0;
	str	first_name;
	str	last_name;
	str	nickname;
	str	phone;
	str	secret;
	str	ret;
	int	index;
	
	system("clear");
	if (this->_index == 0)
	{
		std::cout << BOLD << RED << "PhoneBook is empty." << RESET << std::endl;
        return;
	}
    std::cout << BOLD << BLUE << std::setw(10) << "Index"
              << "|" << std::setw(10) << "First Name"
              << "|" << std::setw(10) << "Last Name"
              << "|" << std::setw(10) << "Nickname" << "|" << RESET << std::endl;
	while (i < _total) {
		std::cout << std::setw(10) << i << "|";
		first_name = this->_array[i].get_first_name();
		last_name = this->_array[i].get_last_name();
		nickname = this->_array[i].get_nickname();
		phone = this->_array[i].get_phone();
		secret = this->_array[i].get_secret();
		if (first_name.length() > 9)
			first_name = first_name.substr(0, 9) + ".";
		if (last_name.length() > 9)
			last_name = last_name.substr(0, 9) + ".";
		if (nickname.length() > 9)
			nickname = nickname.substr(0, 9) + ".";
		std::cout << std::setw(10) << first_name << "|";
		std::cout << std::setw(10) << last_name << "|";
		std::cout << std::setw(10) << nickname << std::endl;
		i++;
	}
	std::cout << std::endl;
	std::cout << BOLD << GREEN << "Enter contact index for personal informations: " << RESET << std::endl;
	std::getline(std::cin, ret);
	index = atoi(ret.c_str());
	if ((index == 0 && ret[0] != '0') || (index > 7 || index < 0)) // ?
	{
		std::cout << BOLD << RED << "Invalid digit. Abort..." << RESET << std::endl;
		return;
	}
	if (index >= this->_total)
	{
		std::cout << BOLD << RED << "No contact found. Abort..." << RESET << std::endl;
		return;
	}
	std::cout << "Name : " << this->_array[index].get_first_name() << std::endl;
	std::cout << "Lastname : " << this->_array[index].get_last_name() << std::endl;
	std::cout << "Nickname : " << this->_array[index].get_nickname() << std::endl;
	std::cout << "Phone number : " << this->_array[index].get_phone() << std::endl;
	std::cout << "Darkest secret : " << this->_array[index].get_secret() << std::endl;
}
