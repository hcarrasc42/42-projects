/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:40:15 by hcarrasc          #+#    #+#             */
/*   Updated: 2024/01/17 10:55:09 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

//Este ejercicio se centra en comprender cómo trabajar con herencia, polimorfismo y 
//manipulación de punteros en el contexto de la programación orientada a objetos.

//Esta función generará aleatoriamente una instancia de A, B o C y la devolverá como un puntero Base
Base	*BaseGenerate(void)
{
    std::srand(std::time(0));
	int	random = std::rand() % 3;
    if (random == 0) {
		std::cout << "A" << std::endl;
        return (new A());
	}
    else if (random == 1) {
		std::cout << "B" << std::endl;
		return (new B());
	}
    else {
		std::cout << "C" << std::endl;
        return (new C());
	}
}

//Esta función imprimirá el tipo real del objeto al que apunta p: "A", "B" o "C".
void identify(Base *p)
{
    std::cout << "ident. * = ";
	if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
	else
		std::cout << "NULL" << std::endl;
}

// Esta función imprimirá el tipo real del objeto referenciado por p: "A", "B" o "C". 
void identify(Base &p)
{
	std::cout << "ident. & = ";
	try {
		A	&a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch (const std::bad_cast &e) {
		try {
			B	&b = dynamic_cast<B &>(p);
			(void)b;
			std::cout << "B" << std::endl;
		}
		catch (const std::bad_cast &e) {
			try {
				C	&c = dynamic_cast<C &>(p);
				(void)c;
				std::cout << "C" << std::endl;
			}
			catch (const std::bad_cast &e) {
				std::cout << "NULL" << std::endl;
			}
		}
	}
}

int main() {
    std::cout << "===== Generando un puntero Base * =====" << std::endl;
    Base *ptr = NULL; // Base *ptr = NULL; es equivalente a Base *ptr = 0;

    std::cout << std::endl << "===== ptr = NULL =====" << std::endl;
    identify(ptr); // identify(*ptr) no funcionará porque ptr es NULL

    std::cout << std::endl << "===== ptr = generate() =====" << std::endl;
    ptr = BaseGenerate(); // ptr ahora apunta a una instancia de A, B o C
    identify(ptr); // identify(*ptr) funcionará porque ptr no es NULL
    identify(*ptr); // identify(ptr) no funcionará porque ptr es un puntero

    delete(ptr);
    return 0;
}
