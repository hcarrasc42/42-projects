/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:13:53 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/10/27 13:19:11 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) {
	this->type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
	return ;
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat destructor called" << std::endl;
	return ;
}

WrongCat::WrongCat(WrongCat const &src) {
	*this = src;
	std::cout << "WrongCat copy constructor called" << std::endl;
	return ;
}

WrongCat		&WrongCat::operator=(WrongCat const &src) {
	this->type = src.getType();
	return (*this);
}

void			WrongCat::makeSound(void) const {
	std::cout << "WrongMeow!!!" << std::endl;
	return ;
}
