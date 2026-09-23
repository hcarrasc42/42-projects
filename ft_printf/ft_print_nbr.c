/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 09:59:35 by hcarrasc          #+#    #+#             */
/*   Updated: 2022/06/06 10:00:41 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(int nbr)
{
	int	stock;

	stock = 0;
	if (nbr == -2147483648)
	{
		return (write(1, "-2147483648", 11));
	}
	if (nbr < 0)
	{
		stock += write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		stock += ft_print_nbr(nbr / 10);
	}
	nbr = nbr % 10;
	if (nbr < 10)
	{
		stock += ft_print_char(nbr + '0');
	}
	return (stock);
}
