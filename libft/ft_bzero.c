/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 10:05:44 by hcarrasc          #+#    #+#             */
/*   Updated: 2022/04/08 10:32:39 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	size_t	ind;

	ind = 0;
	while (ind < n)
	{
		((unsigned char *)str)[ind] = 0;
		ind++;
	}
}

/*int main(void)
{
	char str[] = "hola";
	size_t n = 2;

	ft_bzero(str, n);
	printf ("%s", str);
	return (0);
}*/