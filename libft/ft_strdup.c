/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 09:37:04 by hcarrasc          #+#    #+#             */
/*   Updated: 2022/04/22 11:03:36 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char		*str;
	size_t		size;

	size = ft_strlen(s1);
	str = (char *) ft_calloc(size + 1, 1);
	if (str == NULL)
		return (NULL);
	return ((char *)ft_memmove(str, s1, size));
}
