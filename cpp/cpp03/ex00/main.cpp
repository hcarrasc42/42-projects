/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:05:30 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/10/26 13:25:07 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
	std::cout << "\n\n### TESTING ClapTrap ###\n" << std::endl;
	{
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		ClapTrap d("Hasi");

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		d.attack("Mikel");
		d.takeDamage(11);
		d.beRepaired(12);
		d.takeDamage(15);
		d.attack("Mikel");
		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	}
	return (0);
}
