/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:19:26 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/10/30 12:50:08 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) {
	Animal("Cat");
	this->catBrain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
	return ;
}

Cat::~Cat(void) {
	delete this->catBrain;
	std::cout << "Cat destructor called" << std::endl;
	return ;
}

void	Cat::makeSound(void) const {
	std::cout << "Miaouuuu" << std::endl;
}

void	Cat::getIdeas(void)const {
	for (int i = 0; i < 3; i++) {
		std::cout << "\tIdea " << i << " of the Cat is: " << this->catBrain->getIdea(i) << std::endl;
	}
}

void	Cat::setIdea(int index, std::string idea) {
		this->catBrain->setIdea(index, idea);
}
