/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:19:36 by hcarrasc          #+#    #+#             */
/*   Updated: 2024/01/12 12:18:57 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// Llama al constructor de la clase padre Form y le pasa los parametros
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm(src)
{
	*this = src;
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	return ;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &src)
{
	(void)src;
	return (*this);
}

std::string		RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

void			RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (this->getSignedStatus() == false) // Si el formulario no esta firmado
		throw AForm::FormNotSignedException(); // Lanza una excepcion
	else if (executor.getGrade() > this->getGradeToExecute()) // Si el burócrata tiene un grado mayor al necesario para ejecutar el formulario
		throw AForm::GradeTooLowException(); // Lanza una excepcion
	else
		std::cout << this->getTarget() << "bzzzzz! has been robotomized." << std::endl; // Imprime el mensaje de exito
	return ;
}

std::ostream	&operator<<(std::ostream &str, RobotomyRequestForm const &form)
{
	str << "Form name: " << form.getName() << std::endl;
	str << "Form grade to sign: " << form.getGradeToSign() << std::endl;
	str << "Form grade to execute: " << form.getGradeToExecute() << std::endl;
	str << "Form is signed: " << form.getSignedStatus() << std::endl;
	return (str);
}
