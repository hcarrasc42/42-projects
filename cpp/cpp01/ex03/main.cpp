/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:14:11 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/10/20 13:40:51 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void) {
	{
		Weapon club = Weapon("crude spiked club"); // Weapon is a class
		HumanA bob("Bob", club); // HumanA is a class
		bob.attack(); // Bob attacks with his crude spiked club
		club.setType("SOME other type of club"); // setType is a method of Weapon
		bob.attack(); // Bob attacks with his SOME other type of club
	}
	{
		Weapon club = Weapon("crude spiked club"); // Weapon is a class	
		HumanB jim("Jim"); // HumanB is a class
		jim.setWeapon(club); // setWeapon is a method of HumanB
		jim.attack(); // Jim attacks with his crude spiked club
		club.setType("some other type of club"); // setType is a method of Weapon
		jim.attack(); // Jim attacks with his some other type of club
	}
	return 0;
}
