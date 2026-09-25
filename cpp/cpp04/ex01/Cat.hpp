/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:19:21 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/10/30 12:20:43 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
	private:
		Brain *catBrain;
	public:
		Cat(void);
		~Cat(void); // destructor virtual para que se llame al destructor de la clase derivada

		void	makeSound(void) const; // función que imprime el sonido del animal
		void 	getIdeas(void) const; // función que devuelve el array de ideas
		void	setIdea(int index, std::string idea);
};

#endif
