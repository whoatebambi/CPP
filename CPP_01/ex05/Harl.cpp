/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcouserg <fcouserg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:16:51 by fcouserg          #+#    #+#             */
/*   Updated: 2024/11/24 19:13:45 by fcouserg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void	Harl::complain(std::string level)
{
	std::string level_name[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	void	(Harl::*ft_array_pointer[])() = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	 
	for (int i = 0; i < 4; i++){
		if (!level_name[i].compare(level))
		{
			(this->*ft_array_pointer[i])();
			return ;
		}
	}
	std::cout << "No matching complaints found for: " << level << std::endl;
	std::cout << "Usage: ./harl [LEVEL]" << std::endl;
	std::cout  << "LEVEL = [DEBUG || INFO || WARNING || ERROR]" << std::endl;
}

void	Harl::_debug(void){
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << std::endl;
}

void	Harl::_info(void){
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger ! If you did, I wouldn't be asking for more !"  << std::endl;
}

void	Harl::_warning(void){
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::_error(void){
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}
