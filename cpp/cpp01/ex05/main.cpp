/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:17:23 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/10/20 13:45:11 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main() {
	Harl	harl = Harl();

	harl.complain("debug"); // debug
	harl.complain("info"); // info
	harl.complain("warning"); // warning
	harl.complain("error"); // error
	harl.complain("invalid"); // invalid
	return 0;
}
