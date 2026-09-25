/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:04:42 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/10/27 13:26:05 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) {
	std::cout << "WrongAnimal default constructor called" << std::endl;
	return ;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal destructor called" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src) {
	*this = src;
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	return ;
}

WrongAnimal		&WrongAnimal::operator=(WrongAnimal const &src) {
	this->type = src.getType();
	return (*this);
}

std::string		WrongAnimal::getType(void) const {
	return (this->type);
}

void			WrongAnimal::makeSound(void) const {
	std::cout << "WrongAnimal!!!" << std::endl;
	return ;
}
