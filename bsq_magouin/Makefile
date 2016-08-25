# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/29 11:06:57 by jcamhi            #+#    #+#              #
#    Updated: 2015/07/30 20:23:56 by jcamhi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

SRC = ft_atoi.c \
	  ft_io.c \
	  ft_string.c \
	  handle_input.c \
	  main.c \
	  solver.c \
	  input2.c

TMP = ft_atoi.o \
	  ft_io.o \
	  ft_string.o \
	  handle_input.o \
	  main.o \
	  solver.o \
	  input2.o

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra -c $(SRC)
	gcc -Wall -Werror -Wextra -o $(NAME) $(TMP)

clean:
	rm -f $(TMP)
fclean: clean
	rm -f $(NAME)

re: fclean all
