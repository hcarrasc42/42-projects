/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:51:02 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/10/31 13:01:25 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice: public AMateria {
	private:
		std::string	_type;
	public:
		Ice(void);
		Ice(const Ice &copy);
		~Ice(void);

		Ice	&operator=(const Ice &copy);

		AMateria*	clone(void) const;
		void		use(ICharacter &target);
};

#endif
