/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:25:06 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/10/27 12:31:45 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) {
	Animal("Dog");
	std::cout << "Dog default constructor called" << std::endl;
	return ;
}

Dog::~Dog(void) {
	std::cout << "Dog destructor called" << std::endl;
	return ;
}

void	Dog::makeSound(void) const {
	std::cout << "Guau Guau" << std::endl;
}
