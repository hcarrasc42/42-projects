/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:58:55 by hcarrasc          #+#    #+#             */
/*   Updated: 2024/01/03 14:24:35 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade) { // Constructor
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat(void) { // Destructor
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) { // Copy
	*this = src;
	return ;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src) { // Assignment
	if (this != &src) {}
		_grade = src.getGrade();
	return (*this);
}

std::string Bureaucrat::getName(void) const { // const at the end of the function means that the function will not modify the object
	return (_name);
}

int Bureaucrat::getGrade(void) const {
	return (_grade);
}

void	Bureaucrat::incrementGrade(void) {
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade--;
}

void	Bureaucrat::decrementGrade(void) {
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade++;
}

void	Bureaucrat::signForm(AForm &Aform) {
	try {
		Aform.beSigned(*this);
		std::cout << _name << " signs " << Aform.getName() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << _name << " cannot sign " << Aform.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const &Aform) {
	try {
		Aform.execute(*this);
		std::cout << _name << " executes " << Aform.getName() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << _name << " cannot execute " << Aform.getName() << " because " << e.what() << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade is too low");
}

std::ostream& operator<<(std::ostream &outputStream, const Bureaucrat &ref)
{
	outputStream << ref.getName() << ", bureaucrat grade " << ref.getGrade();
	return (outputStream);
}
