/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:03:28 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/10/26 14:34:41 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) {
	this->Name = name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	this->guardMode = false;
	std::cout << "ScavTrap " << this->Name << " has been created" << std::endl;
	return ;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->Name << " has been destroyed" << std::endl;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const & src) { // constructor de copia
	*this = src;
	std::cout << "ScavTrap " << this->Name << " has been created by copy" << std::endl;
	return ;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const & rhs) { // operador de asignación
	this->Name = rhs.Name;
	this->hitPoints = rhs.hitPoints;
	this->energyPoints = rhs.energyPoints;
	this->attackDamage = rhs.attackDamage;
	return (*this);
}

void	ScavTrap::attack(std::string const & target) {
	if (energyPoints == 0) {
		std::cout << "ScavTrap " << this->Name << " has no energy points!"
		<< std::endl;
		return ;
	}
	if (hitPoints <= 0) {
		std::cout << "ScavTrap " << this->Name << " has no hit points!"
		<< std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->Name << " attacks " << target
	<< ", causing " << this->attackDamage << " points of damage!"
	<< std::endl;
	energyPoints--;

	return ;
}

void	ScavTrap::guardGate(void) {
	if (hitPoints == 0) {
		std::cout << "ScavTrap " << this->Name << " has no hit points!"
		<< std::endl;
		return ;
	}
	if (this->guardMode == true) {
		std::cout << "ScavTrap " << this->Name << " has already enterred in Gate keeper mode"
		<< std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->Name << " has enterred in Gate keeper mode"
	<< std::endl;
	this->guardMode = true;
	return ;
}
