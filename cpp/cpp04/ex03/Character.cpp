/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:44:18 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/10/31 12:50:39 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string name) {
	this->_name = name;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	std::cout << "Character " << this->_name << " was created" << std::endl;
	return ;
}

Character::Character(const Character &copy) {
	this->_name = copy._name;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = copy._inventory[i];
	std::cout << "Character " << this->_name << " was copied" << std::endl;
	return ;
}

Character::~Character(void) {
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i] != NULL)
			delete (this->_inventory[i]);
	}
	std::cout << "Character " << this->_name << " was destroyed" << std::endl;
	return ;
}

Character	&Character::operator=(const Character &copy) {
	this->_name = copy._name;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = copy._inventory[i];
	return (*this);
}

std::string const & Character::getName() const {
	return (this->_name);
}

void Character::equip(AMateria* m) {
	if (m == NULL) {
		std::cout << "Materia is NULL" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL) {
			this->_inventory[i] = m;
			std::cout << "Materia " << m->getType() << " was equipped" << std::endl;
			break ;
		}
	}
	return ;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 3) {
		std::cout << "Index out of range (unequip)" << std::endl;
		return ;
	}
	this->_inventory[idx] = NULL;
	std::cout << "Materia was unequipped" << std::endl;
	return ;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 3) {
		std::cout << "Index out of range (use)" << std::endl;
		return ;
	}
	if (this->_inventory[idx] != NULL) {
		this->_inventory[idx]->use(target);
	} else {
		std::cout << "No materia in this slot" << std::endl;
	}
	return ;
}
