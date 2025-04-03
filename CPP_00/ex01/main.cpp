/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcouserg <fcouserg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:16:51 by fcouserg          #+#    #+#             */
/*   Updated: 2024/11/13 14:34:51 by fcouserg         ###   ########.fr       */
/*                                                                         f   */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	PhoneBook;
	std::string line("INIT");
	
	while (!std::cin.eof() && line != "EXIT" && line[0] != '\0')
	{
		std::cout << BOLD << BLUE << "Enter ADD, SEARCH or EXIT:" << RESET << std::endl;
		std::getline(std::cin >> std::ws, line);
		if (std::cin.fail())
		{
        	std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Error with Getline function, please try again";
        } 
		else if (line == "ADD")
			PhoneBook.add_contact();	
		else if (line == "SEARCH")
			PhoneBook.search_contact();
	}
	return (0);
}
