/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:25:15 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/10/30 12:20:16 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	private:
		Brain *dogBrain;
	public:
		Dog(void);
		~Dog(void);

		void	makeSound(void) const;
		void	getIdeas(void) const; // Funcion que devuelve el array de ideas
		void	setIdea(int index, std::string idea);
};

#endif
