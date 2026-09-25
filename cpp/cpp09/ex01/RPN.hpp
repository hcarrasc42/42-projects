/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:49:56 by hcarrasc          #+#    #+#             */
/*   Updated: 2024/01/31 16:43:58 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN {
	private:
		std::stack<int> _stack;
	public:
		RPN();
		RPN(const RPN& obj);
		~RPN();

		RPN& operator=(const RPN& obj);

		void 	showStack() const;
		void 	addNumber(int num);
		int 	makeOperation(char optr);

		std::stack<int> getStack() const;
};

std::ostream& operator<<(std::ostream& os, const RPN& obj);

#endif
