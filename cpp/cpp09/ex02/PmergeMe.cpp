/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:24:47 by hcarrasc          #+#    #+#             */
/*   Updated: 2024/02/02 17:05:02 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
	
}

PmergeMe::PmergeMe(const PmergeMe& obj) {
	*this = obj;
}

PmergeMe::~PmergeMe() {
	
}

PmergeMe& PmergeMe::operator=(const PmergeMe& obj) {
	_vSequence = obj.getVector();
	return *this;
}

std::ostream& operator<<(std::ostream& os, const PmergeMe& obj) {
	std::cout << "Vector: ";
	showContainer(obj.getVector());
	std::cout << "Deque:  ";
	showContainer(obj.getDeque());
	return os;
}

std::vector<int> PmergeMe::getVector() const {
	return _vSequence;
}

std::deque<int> PmergeMe::getDeque() const {
	return _dSequence;
}

void PmergeMe::sort(char **av) {
	clock_t vecEndTime;
	clock_t	vecStartTime;
	clock_t	deqEndTime;
	clock_t	deqStartTime;

	// vector
	vecStartTime = clock(); // vStartTime se inicia con el tiempo actual
	for (size_t i = 1; av[i]; i++) { 
		_vSequence.push_back(std::atof(av[i])); // Se convierte cada string a un float y se agrega al _vSequence
	}
	mergeInsert(_vSequence); // Se aplica el algoritmo de ordenación merge-insert 
	vecEndTime = clock(); // vEndTime se inicia con el tiempo actual

	// deque
	deqStartTime = clock();
	for (size_t i = 1; av[i]; i++) {
		_dSequence.push_back(std::atof(av[i]));
	}
	mergeInsert(_dSequence); // Se aplica el algoritmo de ordenación merge-insert
	deqEndTime = clock();

	std::cout << "Before: ";
	for (size_t i = 1; av[i]; i++)
		std::cout << av[i] << " ";
	std::cout << "\n";
	std::cout << "After:  ";
	showContainer(_vSequence);
	std::cout << "Time to process a range of " << _vSequence.size() << " elements with std::vector : " << 1000000.0 * (vecEndTime - vecStartTime) / CLOCKS_PER_SEC << " us\n"; // Se muestra el tiempo que se tardó en ordenar el vector
	std::cout << "Time to process a range of " << _dSequence.size() << " elements with std::deque  : " << 1000000.0 * (deqEndTime - deqStartTime) / CLOCKS_PER_SEC << " us\n";
}
