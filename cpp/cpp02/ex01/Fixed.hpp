/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:41:22 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/10/23 12:36:57 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int					_value;
		static const int	_bits = 8;
	public:
		Fixed(void);
		Fixed(const int intValue); // constructor from int
		Fixed(const float intFloat);  // constructor from float
		Fixed(const Fixed& copy); // copy constructor
		~Fixed(void);

		Fixed	&operator=(const Fixed &rhs); // overload of the assignation operator
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat() const;
		int		toInt() const;
		
};
std::ostream    &operator<<(std::ostream &o, Fixed const &fixed); // overload of the << operator

#endif
