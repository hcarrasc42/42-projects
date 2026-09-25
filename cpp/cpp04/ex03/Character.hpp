/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:23:08 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/10/31 13:18:39 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class ICharacter;

class Character: public ICharacter {
	protected:
		std::string _name;
		AMateria	*_inventory[4];
	public:
		Character(std::string name);
		Character(const Character &copy);
		~Character();

		Character	&operator=(const Character &copy);

		std::string const & getName() const; //Devuelve el nombre del personaje
		void equip(AMateria* m); //Equipa una materia
		void unequip(int idx); //Desequipa una materia
		void use(int idx, ICharacter& target); //Utiliza la Materia y pasa el objetivo a la función AMateria::use
};

#endif
