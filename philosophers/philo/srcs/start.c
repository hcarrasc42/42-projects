/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:01:01 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/01/20 13:55:50 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

void	free_philo(t_rules *rules)
{
	if (rules->philo)
		free(rules->philo);
	if (rules->fork)
		free(rules->fork);
}

void	init_mutex(t_rules *rules)
{
	int	i;

	i = 0;
	pthread_mutex_init(&rules->msg, 0);
	pthread_mutex_init(&rules->msg_eat, 0);
	pthread_mutex_init(&rules->check_die, 0);
	pthread_mutex_init(&rules->check_eat, 0);
	while (i < rules->num_philo)
	{
		if (pthread_mutex_init(&rules->fork[i], 0))
			return ;
		i++;
	}
}

void	destroy_mutex(t_rules *rules)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&(rules->msg));
	pthread_mutex_destroy(&(rules->msg_eat));
	pthread_mutex_destroy(&rules->check_die);
	pthread_mutex_destroy(&rules->check_eat);
	while (i < rules->num_philo)
	{
		pthread_mutex_destroy(&(rules->fork[i]));
		i++;
	}
}

void	*philo_thread(void *void_p)
{
	t_philo	*phi;
	t_rules	*rul;

	phi = (t_philo *)void_p;
	rul = phi->rules;
	if (phi->id % 2)
		ft_sleep(rul->time_eat);
	while (1)
	{
		ft_eat(phi);
		if (phi->eat == rul->philo_eat)
			return (0);
		print_philo(rul, "is sleeping", BLUE, phi->id);
		ft_sleep(rul->time_sleep);
		print_philo(rul, "is thinking", CYAN, phi->id);
	}
	return (0);
}

void	start_pro(t_rules *rules)
{
	int		i;
	t_philo	*phi;

	i = 0;
	phi = rules->philo;
	init_mutex (rules);
	while (i < rules->num_philo)
	{
		if (pthread_create(&phi[i].pth_id, 0, &philo_thread, &rules->philo[i]))
			return ;
		i++;
	}
	while (check_die(rules) == 0)
	{
		pthread_mutex_unlock(&rules->check_eat);
		if (check_eat(rules))
		{
			pthread_mutex_unlock(&rules->check_eat);
			break ;
		}
		pthread_mutex_unlock(&rules->check_eat);
	}
	destroy_mutex(rules);
	free_philo(rules);
}
