/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:58:20 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/10/31 12:58:47 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") {
	std::cout << "Cure was created" << std::endl;
	return ;
}

Cure::Cure(const Cure &copy) : AMateria(copy) {
	std::cout << "Cure was copied" << std::endl;
	return ;
}

Cure::~Cure(void) {
	std::cout << "Cure was destroyed" << std::endl;
	return ;
}

Cure	&Cure::operator=(const Cure &copy) {
	this->_type = copy._type;
	return (*this);
}

AMateria*	Cure::clone(void) const {
	Cure *clone = new Cure(*this);
	return (clone);
}

void		Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
	return ;
}
