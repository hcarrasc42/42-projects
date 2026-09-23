# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/21 11:04:40 by hcarrasc          #+#    #+#              #
#    Updated: 2023/01/20 13:27:11 by hcarrasc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	philo
DIR_OBJS		=	objs/
CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra -g

SRCS			=	srcs/main.c						\
					srcs/utils/ft_atoi.c			\
					srcs/utils/ft_calloc.c			\
					srcs/err.c						\
					srcs/philo.c					\
					srcs/start.c					\
					srcs/aux.c						\
					srcs/actions.c					\

OBJS			=	$(SRCS:.c=.o)
PREFIXED	=	$(addprefix $(DIR_OBJS), $(OBJS))

$(DIR_OBJS)%.o : %.c
	@mkdir -p $(DIR_OBJS)/srcs
	@mkdir -p $(DIR_OBJS)/srcs/utils
	@echo "${YELLOW}Compiling with >>${RESET} $(CC) $(CFLAGS):\t $<"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(PREFIXED)
	@$(CC) $(CFLAGS) -o $(NAME) $(PREFIXED)
	@echo "\n${GREEN}Mandatory part compiled!${RESET}\n"


all: $(NAME)

clean:
	@rm -rf $(OBJS) $(DIR_OBJS)
	@echo "\n${BLUE}Cleaned!${RESET}\n"

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re print

GREEN			=	"\\x1b[32m"
RED				=	"\\x1b[31m"
YELLOW			=	"\\x1b[33m"
BLUE			=	"\\x1b[34m"
RESET			=	"\\x1b[37m"
ORANGE			=	"\\x1b[38m"
