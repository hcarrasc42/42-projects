/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:35:32 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/10/31 13:16:28 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter; // Declaracion de la clase ICharacter

// Clase abstracta
class AMateria {
	protected:
		std::string		type;
		AMateria(std::string const & type);
		AMateria(AMateria const &copy);
	public:
		//AMateria const	&operator=(AMateria const &copy);
		virtual ~AMateria(void);

		std::string 			getType(void) const; // Devuelve el tipo de materia
		virtual AMateria* 		clone(void) const = 0; // Devuelve una instancia de la clase de la misma materia
		virtual void 			use(ICharacter& target); // Imprime mensajes dependiendo del tipo de materia y el nombre del personaje
};

# endif
