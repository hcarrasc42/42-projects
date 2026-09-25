/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:05:59 by hcarrasc          #+#    #+#             */
/*   Updated: 2024/01/23 11:01:02 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

// Los contenedores son estructuras de datos que permiten almacenar un conjunto de datos
// VECTOR, LIST Y DEQUE son tres tipos contenedores de C++
int main() {
	int arr[] = {1, 2, 3, 4, 5};
	try {
		std::cout << "VECTOR:\n";
		std::vector<int> numbers(arr, arr + sizeof(arr) / sizeof(arr[0])); // calcula el tamaño del array

		std::cout << *easyfind(numbers, 2) << "\n";
		std::cout << *easyfind(numbers, 10) << "\n";
	} catch ( const std::exception& e ) {
		std::cout << "Error: " << e.what() << "\n";
	}
	try {
		std::cout << "LIST:\n";
		std::list<int> numbers(arr, arr + sizeof(arr) / sizeof(arr[0]));

		std::cout << *easyfind(numbers, 2) << "\n";
		std::cout << *easyfind(numbers, -10) << "\n";
	} catch ( const std::exception& e ) {
		std::cout << "Error: " << e.what() << "\n";
	}
	try {
		std::cout << "DEQUE:\n";
		std::deque<int> numbers(arr, arr + sizeof(arr) / sizeof(arr[0]));

		std::cout << *easyfind(numbers, 2) << "\n";
		std::cout << *easyfind(numbers, 10) << "\n";
	} catch ( const std::exception& e ) {
		std::cout << "Error: " << e.what() << "\n";
	}
	return 0;
}
