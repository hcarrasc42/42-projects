/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 10:30:48 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/01/20 13:52:29 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "colors.h"
# include "struct.h"

// Libf
int			ft_atoi(char *str);
void		*ft_calloc(size_t count, size_t size);

// Philo
void		init_mutex(t_rules *rules);
int			init_values(char **argv, t_rules *rules);

// Error
int			rules_err(t_rules *rules, char **argv);

// Start
void		start_pro(t_rules *rules);

// Utils
long		t_comp(long time);
long		get_time(void);
int			check_die(t_rules *rules);
int			check_eat(t_rules *rules);
void		print_philo(t_rules *rul, char *str, char *color, int philo);

// Actions
void		ft_sleep(int time);
int			ft_eat(t_philo *philo);

#endif