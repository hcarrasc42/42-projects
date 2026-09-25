/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:07:20 by hcarrasc          #+#    #+#             */
/*   Updated: 2024/01/23 11:12:23 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#define FAST

#include <iostream>
#include <algorithm>
#include <vector>

class Span {
	private:
		std::vector<int> _numbers; // contenedor de numeros
		unsigned int _size;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span& obj);
		~Span();

		Span& operator=( const Span& obj );

		unsigned int getSize() const;
		std::vector<int>::const_iterator getBegin() const;
		std::vector<int>::const_iterator getEnd() const;

		void showNumbers() const;
		void addNumber(int number);
		void addNumber(std::vector<int>::const_iterator itBegin, std::vector<int>::const_iterator itEnd);
		int shortestSpan() const;
		int longestSpan() const;

		class MaxElementsStored : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Maximum number of elements reached";
				}
		};

		class NoEnoughElementsStored : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "One or none element was stored";
				}
		};
};

int absolute(int number);
std::ostream& operator<<( std::ostream& o, const Span& obj );

#endif
