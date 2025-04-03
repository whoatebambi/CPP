/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcouserg <fcouserg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:16:51 by fcouserg          #+#    #+#             */
/*   Updated: 2024/11/24 16:54:58 by fcouserg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	// std::cout << "A zombie has been created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie named " << this->_name << " has been destroyed" << std::endl;
}

void	Zombie::announce( void ){
	std::cout << "Zombie named " << this->_name << " has been created" << std::endl;
}

void	Zombie::setName(std::string name)
{
	// std::cout << "Zombie named " << this->_name << " has been created" << std::endl;
    this->_name = name;
}