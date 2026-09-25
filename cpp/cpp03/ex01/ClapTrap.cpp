/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:05:53 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/10/26 13:26:19 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) {
	this->Name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
	std::cout << "ClapTrap " << this->Name << " has been created" << std::endl;
	return ;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << this->Name << " has been destroyed" << std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const & src) { // constructor de copia
	*this = src;
	std::cout << "ClapTrap " << this->Name << " has been created by copy" << std::endl;
	return ;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const & rhs) { // operador de asignación
	this->Name = rhs.Name;
	this->hitPoints = rhs.hitPoints;
	this->energyPoints = rhs.energyPoints;
	this->attackDamage = rhs.attackDamage;
	return (*this);
}

void		ClapTrap::attack(std::string const & target) {
	if (energyPoints == 0) {
		std::cout << "ClapTrap " << this->Name << " has no energy points!"
		<< std::endl;
		return ;
	}
	if (hitPoints <= 0) {
		std::cout << "ClapTrap " << this->Name << " has no hit points!"
		<< std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->Name << " attacks " << target
	<< ", causing " << this->attackDamage << " points of damage!"
	<< std::endl;
	energyPoints--;

	return ;
}

void		ClapTrap::takeDamage(unsigned int amount) {
	if (hitPoints == 0) {
		std::cout << "ClapTrap " << this->Name << " has no hit points!"
		<< std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->Name << " takes "
	<< amount << " points of damage!" 
	<< std::endl;
	hitPoints -= amount;
	if (hitPoints < 0)
		hitPoints = 0;
	return ;
}

void		ClapTrap::beRepaired(unsigned int amount) {
	int		tmp = hitPoints;
	if (energyPoints == 0) {
		std::cout << "ClapTrap " << this->Name << " has no energy points!"
		<< std::endl;
		return ;
	}
	tmp += amount;
	std::cout << "ClapTrap " << this->Name << " repaired itself from " << this->hitPoints << " hit points to " << tmp << " hit points." << std::endl;
	hitPoints += amount;
	energyPoints--;
	
	return ;
}
