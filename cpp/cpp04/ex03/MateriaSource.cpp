/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:57:41 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/10/31 11:04:37 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) {
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	std::cout << "Materia source was created" << std::endl;
	return ;
}

MateriaSource::MateriaSource(const MateriaSource &copy) {
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = copy._inventory[i];
	std::cout << "Materia source was copied" << std::endl;
	return ;
}

MateriaSource::~MateriaSource(void) {
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i] != NULL)
			delete (this->_inventory[i]);
	}
	std::cout << "Materia source was destroyed" << std::endl;
	return ;
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &copy) {
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = copy._inventory[i];
	return (*this);
}

void 		MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL) {
			this->_inventory[i] = m;
			break ;
		}
	}
	return ;
}

AMateria* 	MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != NULL && this->_inventory[i]->getType() == type)
			return (this->_inventory[i]->clone());
	}
	std::cout << "Materia " << type << " created" << std::endl;
	return (NULL);
}
