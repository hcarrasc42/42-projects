/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:29:51 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/10/31 13:39:17 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include "AMateria.hpp"

class AMateria; //Declaración de clase AMateria

//Intefaz de Character, los metodos son virtuales puros
class ICharacter {
	protected:
		const std::string _name;
	public:
		virtual ~ICharacter() {};

		virtual std::string const & getName() const = 0; //Devuelve el nombre del personaje
		virtual void equip(AMateria* m) = 0; //Equipa una materia
		virtual void unequip(int idx) = 0; //Desequipa una materia
		virtual void use(int idx, ICharacter& target) = 0; //Utiliza la Materia
};
//Funciones virtuales puras:
// Las funciones virtuales puras son declaradas con el modificador
// virtual y el sufijo = 0, lo que indica que no tienen implementación en la clase base y 
// deben ser implementadas en las clases derivadas
#endif
