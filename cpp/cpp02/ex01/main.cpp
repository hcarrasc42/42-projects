/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:56:06 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/10/23 12:40:35 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main() {
	Fixed a; // Se llama al constructor por defecto
	Fixed const b( 10 ); // Se llama al constructor int
	Fixed const c( 42.42f ); // Se llama al constructor float
	Fixed const d( b ); // Se llama al constructor de copia

	a = Fixed( 1234.4321f ); // Se llama al constructor float y al operador de asignación

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl; // toInt() convierte el valor del atributo _value a int
	std::cout << "b is " << b.toInt() << " as integer" << std::endl; // toInt() convierte el valor del atributo _value a int
	std::cout << "c is " << c.toInt() << " as integer" << std::endl; // toInt() convierte el valor del atributo _value a int
	std::cout << "d is " << d.toInt() << " as integer" << std::endl; // toInt() convierte el valor del atributo _value a int
	return 0;
}
