# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 09:50:34 by hcarrasc          #+#    #+#              #
#    Updated: 2022/10/07 09:50:37 by hcarrasc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAME_B = pipex_bonus
CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

HEADER_SRC = pipex.h pipex_bonus.h
HEADER_DIR = includes/
HEADER = $(addprefix $(HEADER_DIR), $(HEADER_SRC))

MPATH_SRCS = pipex.c pipex_access.c pipex_fork.c pipex_utils.c pipex_split.c
MPATH_DIR = mandatory/
MPATH = $(addprefix $(MPATH_DIR), $(MPATH_SRCS))
OBJ_M = $(MPATH:.c=.o)

BPATH_SRCS = pipex_bonus.c pipex_utils_bonus.c
BPATH_DIR = bonus/
BPATH = $(addprefix $(BPATH_DIR), $(BPATH_SRCS))
OBJ_B = $(BPATH:.c=.o)

%.o: %.c $(HEADER) Makefile
				@${CC} ${FLAGS} -c $< -o $@

$(NAME):		$(OBJ_M)
				@$(CC) $(OBJ_M) -o $(NAME)
				@echo -e "$(GREEN)$(NAME) created!$(DEFAULT)"

all:			$(NAME)

bonus:			$(OBJ_B)
				@$(CC) $(OBJ_B) -o $(NAME_B)
				@echo -e "$(GREEN)$(NAME_B) created!$(DEFAULT)"

clean:
				@$(RM) $(OBJ_M)
				@$(RM) $(OBJ_B)
				@echo -e "$(YELLOW)object files deleted!$(DEFAULT)"

fclean:			clean
				@$(RM) $(NAME) $(NAME_B)
				@echo -e "$(RED)all deleted!$(DEFAULT)"

re:				fclean all

.PHONY:		all clean fclean bonus re

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m