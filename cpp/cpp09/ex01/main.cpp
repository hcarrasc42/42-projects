/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:50:54 by hcarrasc          #+#    #+#             */
/*   Updated: 2024/02/02 16:29:28 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// asume que la entrada cumple con las reglas de notacion polaca inversa
int main( int ac, char **av ) {
	if (ac == 2) {
		RPN rpn;
		for (size_t i = 0; av[1][i]; i++) {
			if (av[1][i] >= '0' && av[1][i] <= '9') { // verifica si el caracter es un numero del 0 al 9
				if (av[1][i+1] && av[1][i+1] >= '0' && av[1][i+1] <= '9') { // si hay mas de un digito consecutivo da error
					std::cerr << "Error\n";
					return 1;
				}
				rpn.addNumber(av[1][i] - '0'); // agrega el numero a la pila
			} else if (av[1][i] == '+' || av[1][i] == '-' || av[1][i] == '*' || av[1][i] == '/') { // verifica si el caracter es un operador aritmetico
				if (rpn.makeOperation(av[1][i])) // realiza la operacion y verifica si hubo un error
					return 1;
			} else if (av[1][i] != ' ') { // si el caracter no es un digito, un operador o un espacio en blanco da error
				std::cerr << "Error\n";
				return 1;
			}
		}
		std::cout << rpn; // muestra la pila
	} else {
		std::cerr << "Invalid input\n";
		return 1;
	}
	return 0;
}
