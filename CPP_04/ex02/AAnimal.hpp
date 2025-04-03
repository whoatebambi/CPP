/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florencecousergue <florencecousergue@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:29:01 by fcouserg          #+#    #+#             */
/*   Updated: 2025/02/13 18:02:38 by florencecou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "Brain.hpp"

class AAnimal
{
	protected:
		std::string _type;

	public:
		AAnimal();
		virtual ~AAnimal();
		AAnimal(AAnimal const &src);
		AAnimal	&operator=(AAnimal const &rhs);

		AAnimal(std::string type);
		std::string	getType() const;

		virtual void		makeSound() const = 0; // Pure virtual function
		virtual std::string getIdeas(int index) const = 0; // Pure virtual function
		virtual void        setIdea(int index, const std::string &idea) = 0; // Pure virtual function
};
