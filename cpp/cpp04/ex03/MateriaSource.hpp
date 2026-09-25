/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:55:40 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/10/31 13:20:12 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class IMateriaSource;

class MateriaSource: public IMateriaSource {
	private:
		AMateria	*_inventory[4];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &copy);
		~MateriaSource();

		MateriaSource	&operator=(const MateriaSource &copy);

		void 		learnMateria(AMateria* m); // Copia y almacena la materia pasada como parametro
		AMateria* 	createMateria(std::string const & type); // Crea una nueva materia que coincida con el tipo expecificado	
};

#endif
