/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:54:18 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/10/31 13:01:22 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") {
	std::cout << "Ice was created" << std::endl;
	return ;
}

Ice::Ice(const Ice &copy) : AMateria(copy) {
	std::cout << "Ice was copied" << std::endl;
	return ;
}

Ice::~Ice(void) {
	std::cout << "Ice was destroyed" << std::endl;
	return ;
}

Ice	&Ice::operator=(const Ice &copy) {
	this->_type = copy._type;
	return (*this);
}

AMateria*	Ice::clone(void) const {
	Ice *clone = new Ice(*this);
	return (clone);
}

void		Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	return ;
}
