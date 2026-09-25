/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:43:07 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/10/30 12:51:42 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "Brain constructor called" << std::endl;
	for (int i = 0; i < 100; i++) { // En este for se inicializa el array de ideas
		this->ideas[i] = "idea";
	}
	std::cout << "Brain constructor finished" << std::endl;
	return ;
}

Brain::Brain(Brain const &src) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = src;
	std::cout << "Brain copy constructor finished" << std::endl;
	return ;
}

Brain::~Brain(void) {
	std::cout << "Brain destructor called" << std::endl;
	return ;
}

Brain		&Brain::operator=(Brain const &src) {
	std::cout << "Brain operator = called" << std::endl;
	if (this != &src) {
		for (int i = 0; i < 100; i++) {
			this->ideas[i] = src.ideas[i];
		}
	}
	std::cout << "Brain operator = finished" << std::endl;
	return (*this);
}

const std::string	Brain::getIdea(int index)const
{
	if (index < 100)
		return(this->ideas[index]);
	else
		return ("\033[33mThere is only 100 ideas per brain.\033[0m");
}

void	Brain::setIdea(int index, std::string idea)
{
	if (index >= 0 && index < 100) {
		this->ideas[index] = idea;
	}
	else
		std::cout << "\033[33mThere is only 100 ideas per brain.\033[0m" << std::endl;
}
