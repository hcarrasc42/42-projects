/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:07:31 by hcarrasc          #+#    #+#             */
/*   Updated: 2022/04/22 11:03:13 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h>
#include <string.h> */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	chr;
	int				size;

	if ((unsigned char)c == '\0')
		return ((char *)s + ft_strlen(s));
	if (!ft_strchr(s, (unsigned char)c))
		return (NULL);
	chr = c;
	size = ft_strlen(s) - 1;
	while (s[size])
	{
		if ((unsigned char)s[size] == chr)
			return ((char *)s + size);
		size--;
	}
	return (NULL);
}

/* int main(void)
{
	int c = 97;
	const char *s = "Hola Mundo";

	printf("%s\n", ft_strrchr(s, c));
	printf("%s", strrchr(s, c));
} */