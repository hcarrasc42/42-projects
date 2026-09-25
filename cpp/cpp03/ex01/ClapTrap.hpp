/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:05:56 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/10/26 13:01:41 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
	protected:
		std::string		Name;
		int				hitPoints;
		int				energyPoints;
		int				attackDamage;
	public:
		ClapTrap(); // Constructor por defecto
		ClapTrap(std::string name); // constructor por defecto que recibe un parámetro string
		ClapTrap(ClapTrap const & src); // constructor de copia
		~ClapTrap(void);

		ClapTrap	&operator=(ClapTrap const & rhs); // operador de asignación

		void		attack(std::string const & target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);	
};

#endif
