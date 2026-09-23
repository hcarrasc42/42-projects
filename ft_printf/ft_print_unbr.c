/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 09:59:50 by hcarrasc          #+#    #+#             */
/*   Updated: 2022/06/06 09:59:52 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unbr(unsigned int nbr)
{
	int	stock;

	stock = 0;
	if (nbr >= 10)
	{
		stock += ft_print_unbr(nbr / 10);
	}
	nbr = nbr % 10;
	if (nbr < 10)
	{
		stock += ft_print_char(nbr + '0');
	}
	return (stock);
}
