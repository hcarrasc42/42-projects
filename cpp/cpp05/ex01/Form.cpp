/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:24:24 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/12/29 15:51:28 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string name, int gradeToSing, int gradeToExecute): _name(name), _gradeToSing(gradeToSing), _gradeToExecute(gradeToExecute) { // Constructor
	_signedStatus = false;
	if (gradeToSing < 1 || gradeToExecute < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (gradeToSing > 150 || gradeToExecute > 150)
		throw Bureaucrat::GradeTooLowException();
	_gradeToSing = gradeToSing;
	_gradeToExecute = gradeToExecute;
}

Form::~Form(void) { // Destructor
	return ;
}

Form::Form(Form const &src) { // Copy
	*this = src;
	return ;
}

Form &Form::operator=(const Form &src) { // Assignment
	if (this != &src)
		_signedStatus = src.getSignedStatus();
	return (*this);
}

std::string Form::getName(void) const { // const at the end of the function means that the function will not modify the object
	return (_name);
}

int Form::getSignedStatus(void) const {
	return (_signedStatus);
}

int Form::getGradeToSing(void) const {
	return (_gradeToSing);
}

int Form::getGradeToExecute(void) const {
	return (_gradeToExecute);
}

void Form::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSing)
		throw Bureaucrat::GradeTooLowException();
	else
		_signedStatus = true;
}

const char *Form::GradeTooHighException::what() const throw() {
	return ("Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("Grade is too low");
}

std::ostream& operator<<(std::ostream &outputStream, const Form &ref) {
	outputStream << ref.getName() << " is ";
	if (ref.getSignedStatus() == true)
		outputStream << "signed";
	else
		outputStream << "not signed";
	outputStream << " and require a grade " << ref.getGradeToSing() << " to be signed and a grade " << ref.getGradeToExecute() << " to be executed" << std::endl;
	return (outputStream);
}
