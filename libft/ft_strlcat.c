/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:19:08 by hcarrasc          #+#    #+#             */
/*   Updated: 2022/04/22 11:02:31 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t			size;
	unsigned char	sizedst;

	size = ft_strlen(dst);
	sizedst = dstsize;
	if (sizedst > size)
	{
		ft_strlcpy(dst + size, src, sizedst - size);
	}
	if (sizedst >= size)
		return (ft_strlen(src) + size);
	else
		return (ft_strlen(src) + sizedst);
}

/* int main()
{
	char dest[] = "";
	char src[] = "kaixo";
	size_t val;
	int size;

	size = 5;
	val = ft_strlcat(dest, src, size);
	printf("%s\n", dest);
	printf("%zu", val);
	strlcat(dest, src, size);
	printf("%s", dest);
	return (0);
}*/