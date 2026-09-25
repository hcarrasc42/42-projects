/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:33:31 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/10/26 14:29:46 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap {
	public:
		FragTrap(); // Constructor por defecto
		FragTrap(std::string name); // constructor por defecto que recibe un parámetro string
		FragTrap(FragTrap const & src); // constructor de copia
		
		virtual	~FragTrap(void); // Virtual destructor
		//Virtual: Si no se pone virtual, al llamar al destructor de la clase padre, no se llamará al destructor de la clase hija
		
		FragTrap	&operator=(FragTrap const & rhs); // operador de asignación
		
		void		highFivesGuys(void);
};

#endif
