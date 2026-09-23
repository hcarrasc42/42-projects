/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 09:36:53 by hcarrasc          #+#    #+#             */
/*   Updated: 2022/04/22 11:01:43 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	num;

	j = 0;
	i = 0;
	num = 0;
	while (to_find[num])
		num++;
	if (num == 0)
		return ((char *)&str[0]);
	while (str[i] && i < n)
	{
		if (str[i] == to_find[j])
		{
			while (str[j + i] == to_find[j] && to_find[j] && n > i + j)
				j++;
			if (j == num)
				return ((char *)&str[i]);
		}
		j = 0;
		i++;
	}
	return (NULL);
}

/* int	main(void)
{
	char	str[] = "hola mundo";
	char	to_find[] = "mun";

	printf("%s", ft_strnstr(str, to_find, 20));
	return (0);
} */
