/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:43:14 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/10/30 12:23:03 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain {
	private:
		std::string ideas[100];
	public:
		Brain(void);
		Brain(Brain const &src); // constructor de copia
		
		virtual ~Brain(void);

		Brain		&operator=(Brain const &src);

		const	std::string getIdea(int index) const;
		void 	setIdea(int index, std::string idea);
};

#endif
