/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 10:30:17 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/01/16 14:21:54 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

int	main(int argc, char **argv)
{
	t_rules	rules;

	if (argc != 5 && argc != 6)
	{
		printf("%sErro: Arguments wrong\n", RED);
		return (0);
	}
	if (init_values(argv, &rules))
		return (0);
	start_pro(&rules);
	return (0);
}
