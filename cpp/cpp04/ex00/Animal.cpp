/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:16:34 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/10/27 13:20:49 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) {
	std::cout << "Animal default constructor called" << std::endl;
	return ;
}

Animal::Animal(std::string type) {
	this->type = type;
	std::cout << "Animal constructor called" << std::endl;
	return ;
}

Animal::~Animal(void) {
	std::cout << "Animal destructor called" << std::endl;
	return ;
}

Animal::Animal(Animal const &src) {
	*this = src;
	std::cout << "Animal copy constructor called" << std::endl;
	return ;
}

Animal		&Animal::operator=(Animal const &src) {
	this->type = src.getType();
	return (*this);
}

std::string		Animal::getType(void) const {
	return (this->type);
}

void			Animal::makeSound(void) const {
	std::cout << "Animal!!!" << std::endl;
	return ;
}
