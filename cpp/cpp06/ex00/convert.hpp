/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Numbert.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:03:58 by hcarrasc          #+#    #+#             */
/*   Updated: 2024/01/09 13:02:53 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

#include <iostream>
#include <cstring>
#include <iomanip>
#include <limits>
# include <cmath>

class	convert
{
	private:
		std::string	_str;
		double		_nb;

	public:
		convert(std::string str);
		convert(const convert &src);
		~convert();
		convert	&operator=(const convert &src);
		std::string	getStr(void) const;
		double		getNum(void) const;
		void		convertChar(void) const;
		void		convertInt(void) const;
		void		convertFloat(void) const;
		void		convertDouble(void) const;

	class Impossible : public std::exception
	{
		const char *what() const throw()
		{
			return ("Impossible");
		}
	};

	class NonDisplayable : public std::exception
	{
		const char *what() const throw()
		{
			return ("Non displayable");
		}
	};
};

bool			isValid(const std::string& str);
std::ostream	&operator<<(std::ostream &ost, convert const &nb);

#endif
