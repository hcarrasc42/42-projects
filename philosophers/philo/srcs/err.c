/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:28:14 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/01/23 10:51:26 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

int	last_arg(t_rules *rules, char **argv)
{
	if (argv[5] && rules->philo_eat <= 0)
	{
		printf("%sError: Num times eat\n", RED);
		return (1);
	}
	return (0);
}

int	rules_err(t_rules *rules, char **argv)
{
	if (rules->num_philo < 1 || rules->num_philo > 200)
	{
		printf("%sError: Num philo wrong\n", RED);
		return (1);
	}
	else if (rules->time_die < 60)
	{
		printf("%sError: Time death wrong\n", RED);
		return (1);
	}
	else if (rules->time_eat < 60)
	{
		printf("%sError: Time eat wrong\n", RED);
		return (1);
	}
	else if (rules->time_sleep < 60)
	{
		printf("%sError: Time sleep wrong\n", RED);
		return (1);
	}
	else if (last_arg(rules, argv))
		return (1);
	return (0);
}
