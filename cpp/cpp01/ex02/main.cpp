/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:52:46 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/10/20 13:38:31 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

int	main(void) {
	std::string string = "HI THIS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << &string << std::endl; // address
	std::cout << stringPTR << std::endl; // address
	std::cout << &stringREF << std::endl; // address
	
	std::cout << string << std::endl; // value
	std::cout << *stringPTR << std::endl; // value
	std::cout << stringREF << std::endl; // value
	return (0);
}
