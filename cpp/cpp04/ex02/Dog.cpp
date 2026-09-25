/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:25:06 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/10/30 13:19:57 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal("Dog") {
	this->dogBrain = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
	return ;
}

Dog::~Dog(void) {
	delete this->dogBrain;
	std::cout << "Dog destructor called" << std::endl;
	return ;
}

void	Dog::makeSound(void) const {
	std::cout << "Guau Guau" << std::endl;
}

void	Dog::getIdeas(void)const {
	for (int i = 0; i < 3; i++) {
		std::cout << "\tIdea " << i << " of the Dog is: " << this->dogBrain->getIdea(i) << std::endl;
	}
}

void	Dog::setIdea(int index, std::string idea) {
		this->dogBrain->setIdea(index, idea);
}
