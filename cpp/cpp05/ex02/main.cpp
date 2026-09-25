/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:10:57 by hcarrasc          #+#    #+#             */
/*   Updated: 2024/01/03 14:21:11 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int		main(void)
{
	Bureaucrat		b1("Bureaucrat 1", 1);
	Bureaucrat		b2("Bureaucrat 2", 150);
	ShrubberyCreationForm	scf("Home");
	RobotomyRequestForm		rrf("Bender");
	PresidentialPardonForm	ppf("Zaphod");

	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
	std::cout << scf << std::endl;
	std::cout << rrf << std::endl;
	std::cout << ppf << std::endl;

	b1.signForm(scf);
	b1.signForm(rrf);
	b1.signForm(ppf);

	b1.executeForm(scf);
	b1.executeForm(rrf);
	b1.executeForm(ppf);

	b2.executeForm(scf);
	b2.executeForm(rrf);
	b2.executeForm(ppf);

	return (0);
}
