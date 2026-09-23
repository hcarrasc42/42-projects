/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 10:00:02 by hcarrasc          #+#    #+#             */
/*   Updated: 2022/06/06 10:00:03 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_format(va_list arg, char x)
{
	int	stock;

	stock = 0;
	if (x == 'c')
		stock += ft_print_char(va_arg(arg, int));
	else if (x == '%')
		stock += ft_print_char('%');
	else if (x == 'd' || x == 'i')
		stock += ft_print_nbr(va_arg(arg, int));
	else if (x == 'u')
		stock += ft_print_unbr(va_arg(arg, unsigned int));
	else if (x == 's')
		stock += ft_print_str(va_arg(arg, char *));
	else if (x == 'x')
		stock += ft_print_hex_min(va_arg(arg, unsigned int), x);
	else if (x == 'X')
		stock += ft_print_hex_max(va_arg(arg, unsigned int), x);
	else if (x == 'p')
		stock += ft_print_str("0x") + ft_print_hex_min(va_arg(arg,
					unsigned long long), x);
	return (stock);
}

int	ft_printf(char const *str, ...)
{
	va_list	arg;
	int		i;
	int		stock;

	va_start(arg, str);
	i = 0;
	stock = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			stock += ft_print_format(arg, str[i + 1]);
			i++;
		}
		else
		{
			stock += write(1, &str[i], 1);
		}
		i++;
	}
	va_end(arg);
	return (stock);
}
/* int	main(void)
{
	int	i;
	int	d;
	i = printf("%c%s%d%i%u%x%X%p%%\n",'s', "lala", 5, 5, 5, 15, 16, "hola");
	d = ft_printf("%c%s%d%i%u%x%X%p%%\n",'s', "lala", 5, 5, 5, 15, 16, "hola");
	printf("Esto devuelve el printf original:%d\nY esto el nuestro:%d", i, d);
}
 */

/* int main(void)
{
	printf("%u\n", -1);
	ft_printf("%u", -1);
	return (0);
} */