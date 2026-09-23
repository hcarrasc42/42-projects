/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:11:55 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/01/20 13:52:49 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

void	print_eat(t_rules *rul, int id)
{
	if (rul->philo_die == 0)
		printf("%ld %d %sis eating (%d)%s\n", get_time() - rul->start_time,
			id + 1, YELLOW, rul->philo[id].eat + 1, W);
}

int	ft_eat(t_philo *phi)
{
	t_rules	*rul;

	rul = phi->rules;
	pthread_mutex_lock(&(rul->fork[phi->left_fork]));
	print_philo(rul, "take fork", RED, phi->id);
	pthread_mutex_lock(&(rul->fork[phi->right_fork]));
	print_philo(rul, "take fork", RED, phi->id);
	phi->last_time = get_time();
	print_eat(rul, phi->id);
	ft_sleep(rul->time_eat);
	pthread_mutex_lock(&rul->msg_eat);
	rul->philo[phi->id].eat++;
	pthread_mutex_unlock(&rul->msg_eat);
	pthread_mutex_unlock(&(rul->fork[phi->left_fork]));
	pthread_mutex_unlock(&(rul->fork[phi->right_fork]));
	return (0);
}

void	ft_sleep(int time)
{
	long	end_time;

	end_time = get_time() + time;
	while (get_time() < end_time)
		usleep (50);
}
