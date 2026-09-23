/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_max.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 09:59:18 by hcarrasc          #+#    #+#             */
/*   Updated: 2022/06/06 10:00:57 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_max(unsigned long int numb, char c)
{
	int	stock;

	stock = 0;
	if (c == 'X')
	{
		if (numb >= 16)
		{
			stock += ft_print_hex_max(numb / 16, c);
		}
		stock += ft_print_char("0123456789ABCDEF"[numb % 16]);
	}
	return (stock);
}
