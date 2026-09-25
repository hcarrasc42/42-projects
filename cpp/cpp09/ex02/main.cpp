/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:25:04 by hcarrasc          #+#    #+#             */
/*   Updated: 2024/02/02 16:42:03 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool validSequence(int size, char **input) { 
	if (size == 1) // si no hay numeros en la entrada da error
		return false;
	for (int j = 0; j < size - 1; j++) {
		for (int i = 0; input[j][i]; i++) { // verifica si el caracter es un numero
			if (!std::isdigit(input[j][i]))
			 return false;
		}
	}
	return true;
}

int main( int ac, char **av ) {
	PmergeMe S;

	if (!validSequence(ac, &av[1])) {
		std::cerr << "Error\n";
		return 1;
	}
	S.sort(av);
	return 0;
}