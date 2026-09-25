/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:14:27 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/10/19 12:46:29 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	announceBucle(int N, Zombie *zombieHorde) {
	for (int i = 0; i < N; i++) {
		zombieHorde[i].announce();
	}
	delete[] zombieHorde;
}

Zombie*	zombieHorde( int N, std::string name ) {
	if (N <= 0)
			return (NULL);

	Zombie	*zombieHorde = new Zombie[N];
	for (int i = 0; i < N; i++) {
		zombieHorde[i].setName(name);
	}
	announceBucle(N, zombieHorde);
	return (zombieHorde);
}
