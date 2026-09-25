/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:01:45 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/10/26 14:37:57 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {
	private:
		bool		guardMode;
	public:
		ScavTrap(); // Constructor por defecto
		ScavTrap(std::string name); // constructor por defecto que recibe un parámetro string
		ScavTrap(ScavTrap const & src); // constructor de copia
		~ScavTrap(void);

		ScavTrap	&operator=(ScavTrap const & rhs); // operador de asignación

		void		attack(std::string const & target);
		void		guardGate(void);
};

#endif
