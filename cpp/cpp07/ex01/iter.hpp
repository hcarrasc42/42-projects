/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:18:40 by hcarrasc          #+#    #+#             */
/*   Updated: 2024/01/17 15:44:19 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T, typename Func>
// La funcion iter recibe la direccion de un array, le len del array y una funcion
// La funcion iter recorre el array y aplica la funcion f a cada elemento
void	iter(T *array, size_t len, Func f)
{
	for (size_t i = 0; i < len; i++)
	{
		f(array[i]);
	}
}

template<typename T>
void printElement(const T& element) {
    std::cout << element << " ";
}

#endif
