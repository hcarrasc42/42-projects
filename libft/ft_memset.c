/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:43:44 by hcarrasc          #+#    #+#             */
/*   Updated: 2022/04/08 10:34:14 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)str)[i] = c;
		i++;
	}
	return (str);
}

/* int main (void)
{
	char str[] = "kaixooo";
	int c = 98;
	size_t len = 4;

	ft_memset (str, c, len);
	printf ("%s", str);
	return (0);
} */