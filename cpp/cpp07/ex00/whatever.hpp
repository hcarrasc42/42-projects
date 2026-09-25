/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:20:27 by hcarrasc          #+#    #+#             */
/*   Updated: 2024/01/17 16:20:28 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

//La T se convierte en el tipo de dato que se le pase
template <typename T>
// swap function template
void	swap(T &a, T &b)
{
	T tmp;

	tmp = a;
	a = b;
	b = tmp;
}
template <typename T> 
// min function template
T	min(T a, T b)
{
	if (a < b)
		return (a);
	else
		return (b);
}
template <typename T> 
// max function template
T	max(T a, T b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
#endif
