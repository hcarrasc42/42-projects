/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 09:48:00 by hcarrasc          #+#    #+#             */
/*   Updated: 2022/04/26 10:48:10 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if ((char)s[0] == (char)c)
		return ((char *)s);
	while (s[i] && (char)s[i] != (char)c)
		i++;
	if ((char)c == '\0')
		return (&((char *)s)[i]);
	if (s[i] == '\0')
		return (NULL);
	return (&((char *)s)[i]);
}
