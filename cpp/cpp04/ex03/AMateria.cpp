/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:35:37 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/10/31 13:09:06 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) {
	this->type = type;
	std::cout << "AMateria default constructor called" << std::endl;
	return ;
}

AMateria::~AMateria(void) {
	std::cout << "AMateria destructor called" << std::endl;
	return ;
}

AMateria::AMateria(AMateria const &src) {
	*this = src;
	std::cout << "AMateria copy constructor called" << std::endl;
	return ;
}

std::string AMateria::getType(void) const {
	return (this->type);
}

void AMateria::use(ICharacter& target) {
	std::cout << "AMateria abstractly used on " << target.getName() << std::endl;
}

/* AMateria		&AMateria::operator=(AMateria const &src) {
	this->type = src.getType();
	return (*this);
} */
