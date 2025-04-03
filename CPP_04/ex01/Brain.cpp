/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florencecousergue <florencecousergue@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:29:01 by fcouserg          #+#    #+#             */
/*   Updated: 2025/02/13 15:15:01 by florencecou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
    std::cout << "🧠 Brain: Default constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = "Hello World!";
}

Brain::~Brain() {
    std::cout << "🧠 Brain: Destructor called" << std::endl;        
}

Brain::Brain(Brain const &src) {
    std::cout << "🧠 Brain: Copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = src.ideas[i];
}

Brain   &Brain::operator=(Brain const &rhs) {
    std::cout << "🧠 Brain: Assignment operator called" << std::endl;
    if (this != &rhs)
    {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = rhs.ideas[i];
    }
    return (*this);
}

std::string Brain::getIdeas(int index) const{
    // std::cout << "Brain::getIdeas" << std::endl;
    if (index >= 0 && index < 100)  
        return this->ideas[index];
    else
        return "ideas must be in range of [0 - 99].";
}

void    Brain::setIdea(int index, const std::string &idea) {
    // std::cout << "Brain::setIdea" << std::endl;
    if (index >= 0 && index < 100)
        this->ideas[index] = idea;
    else
        std::cout << "ideas must be in range of [0 - 99]." << std::endl;
}
