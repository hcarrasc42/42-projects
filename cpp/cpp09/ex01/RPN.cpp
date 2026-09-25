/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:50:21 by hcarrasc          #+#    #+#             */
/*   Updated: 2024/02/02 16:26:59 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {
	
}

RPN::RPN(const RPN& obj) {
	*this = obj;
}

RPN::~RPN() {
	
}

RPN& RPN::operator=(const RPN& obj) {
	_stack = obj.getStack();
	return *this;
}

std::ostream& operator<<(std::ostream& os, const RPN& obj) {
	obj.showStack();
	return os;
}

void RPN::addNumber(int num) {
	_stack.push(num);
}

// makeOperation realiza una operacion aritmetica basica en notacion polaca inversa
int RPN::makeOperation(char optr) {
	int nums[2];

	if (_stack.size() < 2) { // si la pila tiene menos de dos elementos da error
		std::cerr << "Error\n";
		return 1;
	}
	for (int i = 0; i < 2; i++) { 
		nums[i] = _stack.top();
		_stack.pop();
	}
	// optr representa el operador aritmetico
	switch (optr) {
		case '+':
			_stack.push(nums[1] + nums[0]);
			break;
		case '-':
			_stack.push(nums[1] - nums[0]);
			break;
		case '*':
			_stack.push(nums[1] * nums[0]);
			break;
		case '/':
			_stack.push(nums[1] / nums[0]);
			break;
	}

	return 0;
}

void RPN::showStack() const { // muestra la pila
	std::stack<int> copyStack(_stack);

	while (!copyStack.empty()) {
		std::cout << " " << copyStack.top() << "\n";
		copyStack.pop();
	}
}

std::stack<int> RPN::getStack() const { return _stack; }
