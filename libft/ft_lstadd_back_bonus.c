/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 12:30:36 by hcarrasc          #+#    #+#             */
/*   Updated: 2022/04/22 12:36:37 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_list;

	last_list = ft_lstlast(*lst);
	if (*lst == NULL)
		*lst = new;
	else
	{
		if (last_list == NULL)
			return ;
		last_list->next = new;
	}
}
