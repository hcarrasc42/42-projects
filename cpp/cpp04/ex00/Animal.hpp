/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:12:32 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/10/27 13:36:26 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal {
	protected:
		std::string type;
	public:
		Animal(void);
		Animal(std::string type); // constructor por defecto que recibe un parámetro string
		Animal(Animal const &src); // constructor de copia
	
		virtual ~Animal(void); // destructor

		Animal	&operator=(Animal const &src); // sobrecarga del operador de asignación '='

		std::string		getType(void) const;
		virtual 		void makeSound() const;
};
// Se declara "virtual" en la clase base cuando deseas que el polimorfismo 
// se aplique y que las clases derivadas puedan sobrescribir esa función.
#endif
