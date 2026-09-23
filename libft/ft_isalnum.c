/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:21:06 by hcarrasc          #+#    #+#             */
/*   Updated: 2022/04/11 08:41:39 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90)
		|| (c >= 97 && c <= 122)
		|| (c >= 48 && c <= 57))
		return (1);
	return (0);
}

/*int	main(void)
{
	int	nb;

	nb = 68;
	ft_isalpha(nb);
	printf("%d", ft_isalpha(nb));
	return (0);
}*/
