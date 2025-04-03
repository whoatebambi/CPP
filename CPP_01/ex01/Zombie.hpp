/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcouserg <fcouserg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:05:10 by fcouserg          #+#    #+#             */
/*   Updated: 2024/11/24 16:55:03 by fcouserg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	private:
			std::string	_name;
	
	public:
			Zombie();
			~Zombie();

	void announce(void);
	void setName(std::string name);
};

Zombie* zombieHorde( int N, std::string name );

#endif
