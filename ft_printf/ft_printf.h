/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 10:00:11 by hcarrasc          #+#    #+#             */
/*   Updated: 2022/06/07 10:42:55 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(char const *str, ...);
int		ft_print_char(char c);
int		ft_print_str(char *str);
int		ft_print_nbr(int nbr);
int		ft_print_unbr(unsigned int nbr);
int		ft_print_hex_min(unsigned long int nbr, char c);
int		ft_print_hex_max(unsigned long int nbr, char c);
#endif