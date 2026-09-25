/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:01:09 by hcarrasc          #+#    #+#             */
/*   Updated: 2024/01/17 16:17:30 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	try {
		std:: cout << "\nTEST 1:\n";
		Array<int> A(5); // Array de 5 elementos
		std::cout << A;
		A[2] = 42;
		std::cout << A;
		Array<int> B(A); // Copia de A
		B[0] = 100;
		std::cout << A;
		std::cout << B;
		A[1] = 142;
		A[0] = B[0]; 
		std::cout << A;
		std::cout << "Position 0 in the array A = " << A[0] << "\n";
	} catch(std::exception& e) {
		std::cerr << "Error catch: " << e.what() << "\n";
	}
}
