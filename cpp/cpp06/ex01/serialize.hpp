/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:20:19 by hcarrasc          #+#    #+#             */
/*   Updated: 2024/01/17 10:44:25 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZE_HPP
# define SERIALIZE_HPP

#include <iostream>

struct Data
{
	size_t 	i;
};

class serialize {
	private:
		serialize();
		serialize(const serialize &src);

		serialize	&operator=(const serialize &src);
	public:
		~serialize();

		static	uintptr_t	serializer(Data *ptr);
		static	Data		*deserialize(uintptr_t raw);
};

#endif
