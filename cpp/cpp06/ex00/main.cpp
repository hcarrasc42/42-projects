/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:00:22 by hcarrasc          #+#    #+#             */
/*   Updated: 2024/01/15 14:14:56 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		std::string aux = argv[1];
		try
		{
			convert nb(aux);

			std::cout << "Char: ";
			try	{
				nb.convertChar();
			}
			catch(const std::exception& e)	{
				std::cerr << e.what() << std::endl;
			}

			std::cout << "Int: ";
			try	{
				nb.convertInt();
			}
			catch(const std::exception& e)	{
				std::cerr << e.what() << std::endl;
			}

			std::cout << "Float: ";
			try	{
				nb.convertFloat();
			}
			catch(const std::exception& e)	{
				std::cerr << e.what() << std::endl;
			}

			std::cout << "Double: ";
			try	{
				nb.convertDouble();
			}
			catch(const std::exception& e)	{
				std::cerr << e.what() << std::endl;
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	else
		std::cerr << "Error: invalid args" << std::endl;
	return (0);
}
