/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:18:13 by hcarrasc          #+#    #+#             */
/*   Updated: 2024/01/17 16:26:16 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

// La clase array sirve para crear, modificar y acceder a elementos de un array 
// sin tener que preocuparse por la asignacion y liberación de memoria

//La T se convierte en el tipo de dato que se le pase al crear el objeto
template <typename T>
class Array {
	private:
		T* _elements; // array de elementos
		size_t _size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array<T>& obj);
		~Array();

		Array& operator=( const Array<T>& obj );
		T& operator[](int index) const;

		T getElement(int index) const;
		size_t size() const;

		class IndexOutOfRange : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Index out of range";
				}
		};
};

// constructores
template <typename T>
Array<T>::Array() {
	std::cout << "Array: Default constructor called\n";
	_size = 0;
	_elements = NULL;
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n) {
	std::cout << "Array: Parameter constructor called\n";
	_elements = new T[n];
	for (size_t i = 0; i < _size; i++)
		_elements[i] = 0;
}

template <typename T> // constructor copia
Array<T>::Array(const Array<T>& obj) {
	std::cout << "Array: Copy constructor called\n";
	*this = obj;
}

// destructor
template <typename T>
Array<T>::~Array() {
	std::cout << "Array: Destructor called\n";
	delete [] _elements;
}

// sobrecarga de operador
template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& obj) {
	_size = obj.size();
	_elements = new T[_size];
	for (size_t i = 0; i < _size; i++)
		_elements[i] = obj.getElement(i);
	return *this;
}

template <typename T>
T& Array<T>::operator[](int index) const {
	if (index < 0 || index >= (int)_size)
		throw IndexOutOfRange();
	return _elements[index];
}

template <typename T>
std::ostream& operator<<(std::ostream& o, const Array<T>& obj) {
	o << "Array: ";
	for (size_t i = 0; i < obj.size(); i++)
		o << "  Index " << i << " => [" << obj.getElement(i) << "] ";
	o << "\n";
	return o;
}

// funciones miembro
template <typename T>
size_t Array<T>::size() const { 
	return this->_size; 
}

template <typename T>
T Array<T>::getElement(int index) const {
	if (index < 0 || index >= (int)_size)
		throw IndexOutOfRange();
	return _elements[index];
}

#endif
