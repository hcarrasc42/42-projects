/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:22:27 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/10/20 11:26:05 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _weapon(weapon) {
	this->name = name;
}


HumanA::~HumanA() {
	
}

void	HumanA::attack() {
	std::cout << this->name << " attacks with their " << this->_weapon.getType() << std::endl;
}
