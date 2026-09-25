# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/20 13:37:50 by hcarrasc          #+#    #+#              #
#    Updated: 2024/01/12 12:31:49 by hcarrasc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ = $(SRC:.cpp=.o)
CC = c++
RM = rm -f
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
SRC = 	main.cpp						\
		Bureaucrat.cpp					\
		AForm.cpp						\
		ShrubberyCreationForm.cpp		\
		RobotomyRequestForm.cpp			\
		PresidentialPardonForm.cpp		\
		Intern.cpp						\
		
NAME = Intern

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re