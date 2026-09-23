/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 10:06:14 by hcarrasc          #+#    #+#             */
/*   Updated: 2022/04/22 10:59:17 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	int	i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	while (n > 0)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
		n--;
	}
	return ((unsigned char *)dst);
}

/* int main(void)
{
	char src[] = "megalulmus";
	char dest[50];
	size_t n = 3;
	ft_memcpy(dest, src, n);
	printf("%s", dest);
	return (0);
} */