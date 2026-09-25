/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FrapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:33:49 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/10/26 14:26:51 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() {
	std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) {
	this->Name = name;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap " << this->Name << " has been created" << std::endl;
	return ;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->Name << " has been destroyed" << std::endl;
	return ;
}

FragTrap::FragTrap(FragTrap const & src) { // constructor de copia
	*this = src;
	std::cout << "FragTrap " << this->Name << " has been created by copy" << std::endl;
	return ;
}

FragTrap	&FragTrap::operator=(FragTrap const & rhs) { // operador de asignación
	this->Name = rhs.Name;
	this->hitPoints = rhs.hitPoints;
	this->energyPoints = rhs.energyPoints;
	this->attackDamage = rhs.attackDamage;
	return (*this);
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << this->Name << " says: High five guys!" << std::endl;
	return ;
}
