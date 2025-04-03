/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcouserg <fcouserg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:16:51 by fcouserg          #+#    #+#             */
/*   Updated: 2024/11/24 18:41:35 by fcouserg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name){
    this->_name = name;
    this->_weapon = NULL;
} 

HumanB::~HumanB() {}

void HumanB::attack(){
    if (this->_weapon)
        std::cout << _name << " attacks with a " << _weapon->getType() << std::endl;
    else
        std::cout << _name << " can't attack without a weapon " << std::endl;
}

void HumanB::setWeapon(Weapon &weapon){
    _weapon = &weapon;
}
