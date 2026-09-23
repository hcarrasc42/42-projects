# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 12:22:31 by hcarrasc          #+#    #+#              #
#    Updated: 2022/06/06 09:58:59 by hcarrasc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a

SRCS =	ft_printf.c\
		ft_print_char.c\
		ft_print_str.c\
		ft_print_nbr.c\
		ft_print_unbr.c\
		ft_print_hex_min.c\
		ft_print_hex_max.c\

OBJECTS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(OBJECTS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	ar rcs $@ $^

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re