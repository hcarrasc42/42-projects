/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:37:10 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/01/20 13:40:10 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <pthread.h>

typedef struct s_philo
{
	int					id;
	int					eat;
	int					left_fork;
	int					right_fork;
	long				last_time;
	pthread_t			pth_id;
	struct s_rules		*rules;
}	t_philo;

typedef struct s_rules
{
	int					num_philo;
	int					time_die;
	int					time_eat;
	int					time_sleep;
	int					philo_die;
	int					philo_eat;
	int					aux;
	long				start_time;
	pthread_mutex_t		*fork;
	pthread_mutex_t		msg;
	pthread_mutex_t		msg_eat;
	pthread_mutex_t		check_die;
	pthread_mutex_t		check_eat;
	t_philo				*philo;
}	t_rules;

#endif