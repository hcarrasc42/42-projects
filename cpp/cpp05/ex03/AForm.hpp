/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:16:07 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/12/29 16:23:45 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <string.h>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		std::string _name;
		bool		_signedStatus;
		int			_gradeToSign;
		int			_gradeToExecute;

	public:
		AForm(std::string _name, int gradeToSing, int gradeToExecute);
		AForm(AForm const &src);

		virtual ~AForm();

		AForm &operator=(const AForm &src);
		
		std::string		getName(void) const;
		bool			getSignedStatus(void) const;
		int				getGradeToSign(void) const;
		int				getGradeToExecute(void) const;
		void 			beSigned(Bureaucrat &bureaucrat);
		virtual void 	execute(Bureaucrat const &executor) const = 0;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class FormNotSignedException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
	
};

std::ostream& operator<<(std::ostream &outputStream, const AForm &ref);

#endif
