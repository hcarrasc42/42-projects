/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:04:52 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/10/20 11:28:34 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
	this->name = name;
}

HumanB::~HumanB() {
	
}

void	HumanB::attack() {
	if (this->_weapon == NULL)
		std::cout << this->name << " doesn't have a weapon" << std::endl;
	else
		std::cout << this->name << " attacks with their " << this->_weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon weapon) {
	this->_weapon = &weapon;
}
