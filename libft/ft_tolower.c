/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 09:39:22 by hcarrasc          #+#    #+#             */
/*   Updated: 2022/04/08 10:36:14 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <string.h>
#include <stdio.h> */
#include "libft.h"

int	ft_tolower(int ch)
{
	size_t	num;

	if (ch >= 65 && ch <= 90)
	{
		num = ch + 32;
		return (num);
	}
	return (ch);
}

/* int main ()
{
	int c = 69;
	printf("%d\n", ft_tolower(c));
	printf("%d\n", tolower(c));
} */