/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:04:33 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/10/27 13:23:46 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
	protected:
		std::string		type;
	public:
		WrongAnimal(void);
		WrongAnimal(WrongAnimal const &src);
		
		virtual ~WrongAnimal(void);

		WrongAnimal		&operator=(WrongAnimal const &src);

		std::string		getType(void) const;
		void			makeSound(void) const;
};

#endif
