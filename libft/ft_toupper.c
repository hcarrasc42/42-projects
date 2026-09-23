/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 09:03:12 by hcarrasc          #+#    #+#             */
/*   Updated: 2022/04/08 10:36:18 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <string.h>
#include <stdio.h> */
#include "libft.h"

int	ft_toupper(int ch)
{
	size_t	num;

	if (ch >= 97 && ch <= 122)
	{
		num = ch - 32;
		return (num);
	}
	return (ch);
}

/* int main ()
{
	int c = 97;
	printf("%d\n", ft_toupper(c));
	printf("%d\n", toupper(c));
} */
