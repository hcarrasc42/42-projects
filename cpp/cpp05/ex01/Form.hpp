/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:16:07 by hcarrasc          #+#    #+#             */
/*   Updated: 2024/01/12 12:09:22 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <string.h>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		std::string _name;
		bool		_signedStatus;
		int			_gradeToSing;
		int			_gradeToExecute;

	public:
		Form(std::string _name, int gradeToSing, int gradeToExecute);
		Form(Form const &src);

		~Form();

		Form &operator=(const Form &src);
		
		std::string	getName(void) const;
		int			getSignedStatus(void) const;
		int			getGradeToSing(void) const;
		int			getGradeToExecute(void) const;
		void beSigned(Bureaucrat &bureaucrat);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
	
};

std::ostream& operator<<(std::ostream &outputStream, const Form &ref);

#endif
