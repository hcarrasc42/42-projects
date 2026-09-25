/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:14:29 by hcarrasc          #+#    #+#             */
/*   Updated: 2024/01/17 15:48:10 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main() {
    // Ejemplo de prueba con un arreglo de enteros
    int intArray[] = { 1, 2, 3, 4, 5 };
    size_t intArrayLength = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Iterating over intArray: ";
    iter(intArray, intArrayLength, printElement<int>);
    std::cout << std::endl;

    // Ejemplo de prueba con un arreglo de doubles
    double doubleArray[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    size_t doubleArrayLength = sizeof(doubleArray) / sizeof(doubleArray[0]);

    std::cout << "Iterating over doubleArray: ";
    iter(doubleArray, doubleArrayLength, printElement<double>);
    std::cout << std::endl;

    return 0;
}
