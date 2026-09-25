/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:50:59 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/10/31 13:05:20 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure: public AMateria {
	private:
		std::string	_type;
	public:
		Cure(void);
		Cure(const Cure &copy);
		~Cure(void);

		Cure	&operator=(const Cure &copy);

		AMateria*	clone(void) const;
		void		use(ICharacter &target);
};

#endif
