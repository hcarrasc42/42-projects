/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:20:30 by hcarrasc          #+#    #+#             */
/*   Updated: 2024/01/15 13:48:45 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serialize.hpp"

serialize::serialize() {
	return ;
}

serialize::serialize(const serialize &src) {
	*this = src;
	return ;
}

serialize::~serialize() {
	return ;
}

serialize &serialize::operator=(const serialize &src) {
	if (this != &src) {
		*this = src;
	}
	return (*this);
}

// Serializer crea una representacion de serializada del puntero Data
uintptr_t serialize::serializer(Data *ptr) {
	return (reinterpret_cast<uintptr_t>(ptr)); // reinterpret_cast is used to convert a pointer to an integer
}

// Deserr¡ializer revierte el proceso de serialización y restaura el puntero Data
Data *serialize::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data *>(raw)); // reinterpret_cast is used to convert an integer to a pointer
}
