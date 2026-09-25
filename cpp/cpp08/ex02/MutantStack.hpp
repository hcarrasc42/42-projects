/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:44:44 by hcarrasc          #+#    #+#             */
/*   Updated: 2024/01/23 13:54:38 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <list>

template < typename T, typename Container=std::deque<T> >
class MutantStack : public std::stack< T, Container > {
	public:
		MutantStack(){
			return ;
		}
		MutantStack(const MutantStack& obj) {
			*this = obj;
		}
		~MutantStack(){
			return ;
		}

		MutantStack& operator=( const MutantStack& obj ) {
			std::stack<T, Container>::operator=(obj);
			return *this;
		}

		typedef typename Container::iterator iterator;
		typedef typename Container::reverse_iterator reverse_iterator;
		typedef typename Container::const_iterator const_iterator;
		typedef typename Container::const_reverse_iterator const_reverse_iterator;

		iterator begin() {  // Devuelve un iterador al primer elemento del contenedor
			return this->c.begin();
		}
		iterator end() { // Devuelve un iterador al ultimo elemento del contenedor
			return this->c.end();
		}
		reverse_iterator rbegin() { 
			return this->c.rbegin();
		}
		reverse_iterator rend() {
			return this->c.rend();
		}
		const_iterator cbegin() {
			return this->c.cbegin();
		}
		const_iterator cend() {
			return this->c.cend();
		}
		const_reverse_iterator crbegin() {
			return this->c.crbegin();
		}
		const_reverse_iterator crend() {
			return this->c.crend();
		}
};

#endif
