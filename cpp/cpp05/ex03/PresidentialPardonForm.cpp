/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:19:54 by hcarrasc          #+#    #+#             */
/*   Updated: 2024/01/03 14:54:24 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// Llama al constructor de la clase padre Form y le pasa los parametros
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : AForm(src)
{
	*this = src;
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	return ;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &src)
{
	(void)src;
	return (*this);
}

std::string		PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

void			PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->getSignedStatus() == false) // Si el formulario no esta firmado
		throw AForm::FormNotSignedException(); // Lanza una excepcion
	else if (executor.getGrade() > this->getGradeToExecute()) // Si el burócrata tiene un grado mayor al necesario para ejecutar el formulario
		throw AForm::GradeTooLowException(); // Lanza una excepcion
	else
		std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox." << std::endl; // Imprime el mensaje de exito
	return ;
}

std::ostream	&operator<<(std::ostream &str, PresidentialPardonForm const &form)
{
	str << "Form name: " << form.getName() << std::endl;
	str << "Form grade to sign: " << form.getGradeToSign() << std::endl;
	str << "Form grade to execute: " << form.getGradeToExecute() << std::endl;
	str << "Form is signed: " << form.getSignedStatus() << std::endl;
	str << "Form target: " << form.getTarget() << std::endl;
	return (str);
}

