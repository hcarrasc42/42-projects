/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:50:31 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/10/31 13:22:21 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include "AMateria.hpp"

class AMateria;

//Intefaz de MateriaSource, los metodos son virtuales puros
class IMateriaSource {
	public:
		virtual ~IMateriaSource() {};
		
		virtual void 		learnMateria(AMateria*) = 0; // Copia y almacena la materia pasada como parametro
		virtual AMateria* 	createMateria(std::string const & type) = 0; // Crea una nueva materia que coincida con el tipo expecificado
};
//Funciones virtuales puras:
// Las funciones virtuales puras son declaradas con el modificador
// virtual y el sufijo = 0, lo que indica que no tienen implementación en la clase base y 
// deben ser implementadas en las clases derivadas
#endif
