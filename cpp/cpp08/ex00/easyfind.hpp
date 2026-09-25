/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:45:58 by hcarrasc          #+#    #+#             */
/*   Updated: 2024/01/23 11:05:28 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>

class NotFound : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "No ocurrence found";
		}
};

// Easyfind busca un elemento en un contenedor y devuelve un iterador al elemento encontrado
template <typename T>
typename T::iterator easyfind(T cont, int find) {
	typename T::iterator i; // 
	for (i = cont.begin(); i != cont.end(); i++) {
		if (*i == find)
			return (i);
	}
	if (i == cont.end())
		throw NotFound();
	return (i);
}

#endif

