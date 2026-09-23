/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 09:59:42 by hcarrasc          #+#    #+#             */
/*   Updated: 2022/06/06 09:59:44 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	int	i;
	int	stock;

	i = 0;
	stock = 0;
	if (!str)
	{
		return (ft_print_str("(null)"));
	}
	while (str[i])
	{
		stock += ft_print_char(str[i]);
		i++;
	}
	return (stock);
}
