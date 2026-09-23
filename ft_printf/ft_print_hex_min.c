/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_min.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 09:59:27 by hcarrasc          #+#    #+#             */
/*   Updated: 2022/06/06 10:01:03 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_min(unsigned long int numb, char c)
{
	int	stock;

	stock = 0;
	if (c == 'x' || c == 'p')
	{
		if (numb >= 16)
		{
			stock += ft_print_hex_min(numb / 16, c);
		}
		stock += ft_print_char("0123456789abcdef"[numb % 16]);
	}
	return (stock);
}
