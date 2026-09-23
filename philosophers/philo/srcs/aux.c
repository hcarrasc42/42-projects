/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:52:18 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/01/20 13:55:31 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

long	t_comp(long time)
{
	struct timeval	tmp;
	long			sum1;
	long			sum2;

	gettimeofday(&tmp, 0);
	sum1 = (tmp.tv_sec * 1000) + (tmp.tv_usec / 1000);
	sum2 = time;
	return (sum1 - sum2);
}

long	get_time(void)
{
	struct timeval	tmp;

	gettimeofday(&tmp, 0);
	return ((tmp.tv_sec * 1000) + (tmp.tv_usec / 1000));
}

void	print_philo(t_rules *rul, char *str, char *color, int philo)
{
	pthread_mutex_lock(&rul->msg);
	if (rul->philo_die == 0)
		printf("%ld %d %s%s%s\n", get_time() - rul->start_time,
			philo + 1, color, str, W);
	pthread_mutex_unlock(&rul->msg);
}

int	check_eat(t_rules *rules)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (rules->philo_eat)
	{
		while (i < rules->num_philo)
		{
			if (rules->philo[i].eat == rules->philo_eat)
				count++;
			i++;
		}
		if (count == i)
		{
			rules->philo_die = 1;
			pthread_mutex_unlock(&rules->check_eat);
			return (1);
		}
	}
	return (0);
}

int	check_die(t_rules *rules)
{
	pthread_mutex_lock(&rules->check_die);
	if (t_comp(rules->philo->last_time) > rules->time_die)
	{
		print_philo(rules, "is dead", MAGENTA, rules->philo->id);
		rules->philo_die = 1;
		pthread_mutex_unlock(&rules->check_die);
		return (1);
	}
	pthread_mutex_unlock(&rules->check_die);
	return (0);
}
