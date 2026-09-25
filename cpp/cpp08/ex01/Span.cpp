/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:07:17 by hcarrasc          #+#    #+#             */
/*   Updated: 2024/01/23 13:30:27 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _size(0) {
	return ;
}

Span::Span(unsigned int N) : _size(N) {
	return ;
}

Span::Span(const Span& obj) {
	*this = obj;
}

Span::~Span() {}

// Operador de asignación
Span& Span::operator=( const Span& obj ) {
	_numbers.assign(obj.getBegin(), obj.getEnd());
	_size = obj.getSize();
	return *this;
}

unsigned int Span::getSize() const {
	return _size;
}

std::vector<int>::const_iterator Span::getBegin() const {
	return _numbers.begin(); 
}

std::vector<int>::const_iterator Span::getEnd() const {
	return _numbers.end();
}

void Span::showNumbers() const {
	std::cout << "Numbers:\n";
	for (std::vector<int>::const_iterator it = _numbers.begin(); it < _numbers.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << "\n";
}

void Span::addNumber(int number) { // Añade un numero al contenedor
	if (_numbers.size() == _size)
		throw MaxElementsStored();
	_numbers.push_back(number);
}

void Span::addNumber(std::vector<int>::const_iterator itBegin, std::vector<int>::const_iterator itEnd) { // Añade varios numeros al contenedor
	if (_numbers.size() == _size || (unsigned int)absolute(itBegin-itEnd) > _size) 
		throw MaxElementsStored();
	for (; itBegin < itEnd; itBegin++) {
		_numbers.push_back(*itBegin);
	}
}

int Span::shortestSpan() const { // Devuelve el span mas pequeño entre los numeros almacenados
	int shortest = longestSpan();

	for (std::vector<int>::const_iterator it1 = _numbers.begin(); it1 < _numbers.end() - 1; it1++) {
		for (std::vector<int>::const_iterator it2 = it1 + 1; it2 < _numbers.end(); it2++) {
			if (absolute(*it1 - *it2) < shortest)
				shortest = absolute(*it1 - *it2);
		}
	}
	return shortest;
	/*FAST
	std::vector<int> tmp (_numbers.size());
	std::copy(_numbers.begin(), _numbers.end(), tmp.begin());
	std::sort(tmp.begin(), tmp.end());
	for (std::vector<int>::const_iterator it = tmp.begin(); it < tmp.end() - 1; it++) {
		if (absolute(*it - *(it+1)) < shortest)
			shortest = absolute(*it - *(it+1));
	} */
}

int Span::longestSpan() const { // Devuelve el span mas grade entre los numeros almacenados
	if (_numbers.size() <= 1)
		throw NoEnoughElementsStored();
	return (*std::max_element(_numbers.begin(), _numbers.end())
			- *std::min_element(_numbers.begin(), _numbers.end()));
}

int absolute(int number) {
	if (number < 0)
		return -number;
	return number;
}

std::ostream& operator<<( std::ostream& o, const Span& obj ) {
	obj.showNumbers();
	return o;
}
