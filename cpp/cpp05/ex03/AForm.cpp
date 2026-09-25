/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:28:53 by hcarrasc          #+#    #+#             */
/*   Updated: 2024/01/03 14:37:12 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signedStatus(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	return ;
}

AForm::~AForm(void) {
	return ;
}

AForm::AForm(AForm const &src) {
	*this = src;
	return ;
}

AForm	&AForm::operator=(AForm const &src) {
	if (this != &src)
		_signedStatus = src.getSignedStatus();
	return (*this);
}

std::string	AForm::getName(void) const {
	return (_name);
}

bool	AForm::getSignedStatus(void) const {
	return (_signedStatus);
}

int	AForm::getGradeToSign(void) const {
	return (_gradeToSign);
}

int	AForm::getGradeToExecute(void) const {
	return (_gradeToExecute);
}

void	AForm::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign)
		throw Bureaucrat::GradeTooLowException();
	else
		_signedStatus = true;
}

const char *AForm::GradeTooHighException::what() const throw() {
	return ("Grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw() {
	return ("Grade is too low");
}

const char *AForm::FormNotSignedException::what() const throw() {
	return ("Form is not signed");
}

std::ostream& operator<<(std::ostream &outputStream, AForm const &ref) {
	outputStream << ref.getName() << " is ";
	if (ref.getSignedStatus() == true)
		outputStream << "signed";
	else
		outputStream << "not signed";
	outputStream << " and require a grade " << ref.getGradeToSign() << " to be signed and a grade " << ref.getGradeToExecute() << " to be executed";
	return (outputStream);
}
