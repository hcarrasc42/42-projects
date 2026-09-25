/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:41:12 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/10/23 12:37:28 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructor por defecto
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

// Constructor de int
Fixed::Fixed(const int intValue) {
	std::cout << "Int constructor called" << std::endl;
	this->_value = intValue << this->_bits; // Multiplica el valor del int por 2^8
	return ;
}

// Constructor de float
Fixed::Fixed(const float intFloat) {
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(intFloat * (1 << this->_bits)); // Multiplica el valor del float por 2^8
}
// roundf() redondea el valor del float al entero más cercano
// (1 << this->_bits)) es lo mismo que (2^8)

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

// Devuelve el valor del atributo _value en float
float	Fixed::toFloat(void) const {
	return ((float)this->_value / (float)(1 << this->_bits)); // Divide el valor del atributo _value entre 2^8
}
//  return ((float)this->_value / (float)(1 << this->_bits)) equivale a dividir el valor del atributo _value entre 2^8
//El resultado se almacena en un float


// Devuelve el valor del atributo _value en int
int	Fixed::toInt(void) const {
	return (this->_value >> this->_bits); // Divide el valor del atributo _value entre 2^8
}
// (this->_value >> this->_bits) es lo mismo que (this->_value / (2^8))
// Desplaza el valor del atributo _value 8 bits a la derecha

// Sobrecarga del operador << para mostrar el valor del atributo _value
std::ostream	&operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}
