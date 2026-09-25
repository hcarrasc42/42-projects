/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:19:42 by hcarrasc          #+#    #+#             */
/*   Updated: 2024/01/03 14:42:02 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// Llama al constructor de la clase padre Form y le pasa los parametros
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm(src)
{
	*this = src;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	return ;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src)
{
	(void)src;
	return (*this);
}

std::string		ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

void			ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->getSignedStatus() == false) // Si el formulario no esta firmado
		throw AForm::FormNotSignedException(); // Lanza una excepcion
	else if (executor.getGrade() > this->getGradeToExecute()) // Si el burócrata tiene un grado mayor al necesario para ejecutar el formulario
		throw AForm::GradeTooLowException(); // Lanza una excepcion
	else
	{
		std::ofstream	ofs(this->getTarget() + "_shrubbery"); // Crea un archivo con el nombre del target
		ofs << "      /\\      " << std::endl;
		ofs << "     /\\*\\     " << std::endl;
		ofs << "    /\\O\\*\\    " << std::endl;
		ofs << "   /*/\\/\\/\\   " << std::endl;
		ofs << "  /\\O\\/\\*\\/\\  " << std::endl;
		ofs << " /\\*\\/\\*\\/\\/\\ " << std::endl;
		ofs << "/\\O\\/\\/*/\\/O/\\" << std::endl;
		ofs << "      ||      " << std::endl;
		ofs << "      ||      " << std::endl;
		ofs << "      ||      " << std::endl;
		ofs << std::endl;
	}
	return ;
}

std::ostream	&operator<<(std::ostream &str, ShrubberyCreationForm const &form)
{
	str << "Form name: " << form.getName() << std::endl;
	str << "Form grade to sign: " << form.getGradeToSign() << std::endl;
	str << "Form grade to execute: " << form.getGradeToExecute() << std::endl;
	str << "Form is signed: " << form.getSignedStatus() << std::endl;
	return (str);
}
