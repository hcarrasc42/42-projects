/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:55:24 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/10/23 11:54:18 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructor por defecto que inicializa el atributo _value a 0
Fixed::Fixed(void) : _value(0) {
	std::cout << "Default constructor called" << std::endl;
	return ;
}

// Destructor por defecto
Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
	return ;
}

// Constructor de copia
Fixed::Fixed(const Fixed &copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

// Sobrecarga del operador de asignación
Fixed &Fixed::operator=(const Fixed& copy) {
	std::cout << "Assignation operator called" << std::endl;		
    if (this != &copy)
        this->_value = copy.getRawBits();
    return *this;
}

// Devuelve el valor del atributo _value
int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

// Asigna el valor del parámetro raw al atributo _value
void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}
