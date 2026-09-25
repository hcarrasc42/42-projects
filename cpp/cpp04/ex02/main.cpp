/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:11:50 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/10/30 13:31:43 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	Dog	*dog1 = new Dog();
	Cat	*cat1 = new Cat();
	//Animal	*animal1 = new Animal();

	//std::cout << animal1->getType() <<std::endl;
	std::cout << dog1->getType() <<std::endl;
	std::cout << cat1->getType() <<std::endl;

	delete dog1;
	delete cat1;
	return (0);
}
