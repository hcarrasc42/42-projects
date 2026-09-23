/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:42:50 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/01/19 11:58:49 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

/* void	print_phi(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->num_philo)
	{
		printf("philo: %d\n", rules->philo[i].left_fork);
		printf("philo: %d\n", rules->philo[i].right_fork);
		i++;
	}
}
 */
void	init_philos(t_rules *rules)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = rules->philo;
	while (i < rules->num_philo)
	{
		philo[i].id = i;
		philo[i].eat = 0;
		philo[i].left_fork = i;
		philo[i].right_fork = (i + 1) % rules->num_philo;
		philo[i].last_time = rules->start_time;
		philo[i].rules = rules;
		i++;
	}
}

int	init_values(char **argv, t_rules *rules)
{
	rules->num_philo = ft_atoi(argv[1]);
	rules->time_die = ft_atoi(argv[2]);
	rules->time_eat = ft_atoi(argv[3]);
	rules->time_sleep = ft_atoi(argv[4]);
	rules->philo_die = 0;
	rules->philo_eat = 0;
	rules->aux = 0;
	if (argv[5])
		rules->philo_eat = ft_atoi(argv[5]);
	if (rules_err(rules, argv))
		return (1);
	rules->philo = (t_philo *)malloc(sizeof(t_philo) * (rules->num_philo + 1));
	rules->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* (rules->num_philo + 1));
	rules->start_time = get_time();
	init_philos(rules);
	return (0);
}
