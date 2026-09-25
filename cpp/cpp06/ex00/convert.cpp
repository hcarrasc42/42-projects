/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:04:25 by hcarrasc          #+#    #+#             */
/*   Updated: 2024/01/09 13:27:01 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"

convert::convert(std::string str)
{
	this->_str = str;
	if (str.size() == 1)
	{
		if (str[0] >= '0' && str[0] <= '9')
			_nb = std::stoi(str);
		else
			_nb = str[0];
	}
	else if (isValid(str))
		_nb = std::stod(str); // std::stod() converts a string to a double
	else {
		std::cerr << "Invalid input" << std::endl; // std::cerr is used to output errors
		exit(1);
	}
}

convert::convert(const convert &src) : _str(src.getStr()), _nb(src.getNum())
{
	return ;
}

convert::~convert()
{
	return ;
}

convert &convert::operator=(const convert &src)
{
	if (this != &src)
		this->_str = src.getStr();
		this->_nb = src.getNum();
	return (*this);
}

std::string	convert::getStr(void) const
{
	return (this->_str);
}

double	convert::getNum(void) const
{
	return (this->_nb);
}

void	convert::convertChar(void) const
{
	if (std::isnan(_nb) || _nb >= std::numeric_limits<int>::max() || _nb <= -std::numeric_limits<int>::min())
	// std::numeric_limits<int>::max() returns the maximum value of an int
	// std::isnan() checks if a number is not a number
		std::cerr << "impossible" << std::endl;
	else if (_nb < 32 || _nb > 126)
		std::cerr << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(_nb) << "'" << std::endl;
}

void		convert::convertInt(void) const
{
	if (std::isnan(_nb) || _nb >= std::numeric_limits<int>::max() || _nb <= -std::numeric_limits<int>::min())
	// std::numeric_limits<int>::max() returns the maximum value of an int
		std::cerr << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(_nb) << std::endl;
}

void	convert::convertFloat(void) const
{
	float f = static_cast<float>(_nb); // convierte el double a float
	if (f - (int)f != (float)0) // comprueba si el float no es un numero entero
		std::cerr << f << "f" << std::endl; 
	else
		std::cerr << f << ".0f" << std::endl;
}

void	convert::convertDouble(void) const
{
	double d = static_cast<double>(_nb);
	if (d - (int)d != (double)0) // comprueba si el double no es un numero entero
		std::cout << d << std::endl;
	else
		std::cout << d << ".0" << std::endl;
}

std::ostream	&operator<<( std::ostream &ost, convert const &nb)
{
	ost << "convert: " << nb.getNum() << ", str: " << nb.getStr() << std::endl;
	return (ost);
}

// Evalua si la cadena es un numero valido teniendo en cuenta los casos especiales
bool isValid(const std::string& str)
{
	int	dotCount = 0;

	if (str == "inf" || str == "inff" || str == "-inf" ||
		str == "-inff" || str == "nan" || str == "nanf")
		return true;
	for (size_t i = 0; str[i] ; i++)
	{
		if (i == 0 && (str[i] == '-' || str[i] == '+'))
			i++;
		if (!std::isdigit(str[i]) && str[i] != '.'
			&& !(str[i] == 'f' && (i == str.size() - 1)))
			return false;
		if (str[i] == '.')
		{
			dotCount++;
			if (dotCount > 1)
				return false;
		}
	}
	return true;
}
