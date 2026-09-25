/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:21:27 by hcarrasc          #+#    #+#             */
/*   Updated: 2024/01/24 16:26:01 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main( int ac, char **av ) {
	if (ac == 2) {
		BitcoinExchange BTC;
		BTC.checkInput(av[1]);
	}
	else {
		std::cerr << "Error: could not open file.\n";
	}
	return 0;
}
