/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcouserg <fcouserg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:05:10 by fcouserg          #+#    #+#             */
/*   Updated: 2024/11/23 17:11:57 by fcouserg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <cctype>
#include <unistd.h>
#include <cstdlib>
#include <iomanip>
#include <cstdio>
# include <sstream>
# include <limits>

const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";
const std::string MAGENTA = "\033[35m";
const std::string CYAN = "\033[36m";
const std::string WHITE = "\033[37m";
const std::string BOLD = "\033[1m";
const std::string UNDERLINE = "\033[4m";
const std::string INVERSE = "\033[7m";

class PhoneBook
{
	public:
			PhoneBook();
			~PhoneBook();
			void	add_contact();
			void	add_contact_info(const std::string& prompt, std::string& field);
			void	search_contact();
	private:
			int			_index;
			int			_total;
			Contact		_array[8];
};

#endif
