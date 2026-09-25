/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:24:43 by hcarrasc          #+#    #+#             */
/*   Updated: 2024/02/02 17:04:26 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <iostream>
#include <ctime>
#include <vector>
#include <deque>

class PmergeMe {
	private:
		std::vector<int> _vSequence;
		std::deque<int> _dSequence;
	public:
		PmergeMe();
		PmergeMe( const PmergeMe& obj );
		~PmergeMe();

		PmergeMe& operator=( const PmergeMe& obj );

		std::vector<int> getVector() const;
		std::deque<int> getDeque() const;

		void sort(char **av);
};

std::ostream& operator<<(std::ostream& os, const PmergeMe& obj);

template <typename C>
void showContainer(const C& container) {
	for (typename C::const_iterator it = container.cbegin(); it != container.cend(); it++) {
		std::cout << *it << " ";
	}
	std::cout << "\n";
}

template <typename C>
bool isSorted(const C& container) {
	for (typename C::const_iterator it = container.begin(); it != container.end() - 1; it++) {
		if (*it > *(it+1))
			return false;
	}
	return true;
}

template <typename C>
int sortPairs(C& sequence) {
	if (sequence.size() == 2 && *sequence.begin() > *(sequence.end() - 1)) {
		std::swap(*sequence.begin(), *(sequence.end() - 1));
		return 1;
	}

	for (typename C::iterator it = sequence.begin(); it < sequence.end() - 1; it+=2) {
		if (*it < *(it+1))
			std::swap(*it, *(it+1));
	}

	for (typename C::iterator it1 = sequence.begin(); it1 < sequence.end() - 3; it1+=2) {
		for (typename C::iterator it2 = it1 + 2; it2 < sequence.end() - 1; it2+=2) {
			if (*it1 > *(it2)) {
				std::swap(*it1, *it2);
				std::swap(*(it1+1), *(it2+1));
			}
		}
	}

	return 0;
}

template <typename I>
I insertBinarySearch(int num, I first, I last) {
	if (num <= *first)
		return first;
	if (num >= *last && last - first == 1)
		return last + 1;
	if (*first < num && *last > num && last - first == 1)
		return first + 1;
	if (*(first+(floor((last-first)/2))) > num)
		first = insertBinarySearch(num, first, first+(floor((last-first)/2)));
	else
		first = insertBinarySearch(num, first+(floor((last-first)/2)), last);
	return first;
}


template <typename C>
void eraseOdd(C& sequence) {
	if (sequence.size() % 2)
		sequence.erase(sequence.end() - 1);
	for (typename C::iterator it = sequence.begin() + 1; it <= sequence.end(); it++) {
		if (std::is_same<std::deque<int>, C >::value) {
			if ((sequence.end() - it)%2)
				sequence.erase(it);
		} else {
			sequence.erase(it);
		}
	}
}

template <typename C>
C createChain(C& sequence) {
	C b;
	for (typename C::iterator it = sequence.begin(); it < sequence.end(); it+=2) {
		(it == sequence.end() - 1) ? b.push_back(*it) : b.push_back(*(it+1));
	}
	eraseOdd(sequence);
	return b;
}

//La función mergeInsert implementa el algoritmo de ordenación merge-insert para un contenedor genérico.
template <typename C>
void mergeInsert( C& container ) {
	if (isSorted(container) || sortPairs(container)) // verifica si la secuencia ya esta ordenada o si la ordenacion de pares ya ha sio realizada
		return ;
	C b = createChain(container); // createChain crea una nueva secuencia
	for (typename C::iterator it = b.begin(); it < b.end(); it++) {
		if (it == b.begin())
			container.insert(container.begin(), *it);
		else {
			typename C::iterator in = insertBinarySearch(*it, container.begin(), container.end() - 1);
			container.insert(in, *it);
		}
	}
}

#endif