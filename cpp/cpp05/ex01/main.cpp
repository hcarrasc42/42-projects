/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:41:19 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/12/29 15:56:38 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main(void)
{
	Bureaucrat		bob("Bob", 1);
	Bureaucrat		jim("Jim", 150);
	Form			form1("Form1", 1, 1);
	Form			form2("Form2", 150, 150);

	std::cout << bob << std::endl;
	std::cout << jim << std::endl;
	std::cout << form1 << std::endl;
	std::cout << form2 << std::endl;

	try
	{
		form1.beSigned(bob);
		std::cout << form1 << std::endl;
		form2.beSigned(jim);
		std::cout << form2 << std::endl;
		form1.beSigned(jim);
		std::cout << form2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
