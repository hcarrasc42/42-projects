/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:47:01 by hcarrasc          #+#    #+#             */
/*   Updated: 2024/01/17 10:50:03 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serialize.hpp"

//La serialización y deserialización de punteros se utilizan para convertir un puntero 
//a un tipo de datos que se puede almacenar o transmitir y luego recuperar el puntero original

int main() {
	{
		Data D;
		Data *res;
		D.i = -21;

		res = serialize::deserialize(serialize::serializer(&D)); 
		std::cout << "\nTEST 1:\n";
		std::cout << "  before: " << D.i << "\n";
		std::cout << "  after:  " << res->i << "\n";
	}
	{
		uintptr_t i = 42;
		uintptr_t o;

		o = serialize::serializer(serialize::deserialize(i));
		std::cout << "\nTEST 2:\n";
		std::cout << "  before: " << i << "\n";
		std::cout << "  after:  " << o << "\n";
	}
	std::cout << "\n";
	return 0;
}
