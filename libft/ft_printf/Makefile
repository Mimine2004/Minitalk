# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/17 11:47:31 by adelattr          #+#    #+#              #
#    Updated: 2025/01/03 14:07:33 by hhecquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror 

SRCS =	ft_printf.c 			\
		ft_printf_tools.c 		\
		ft_printf_basictools.c 	\
		ft_putflags.c			\
		ft_putahex.c			\
		ft_printf_utils.c					

INCLUDES = ft_printf.h

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) ft_printf.h
	ar -rcs $(NAME) $(OBJ)

bonus: $(NAME)
	ar -rcs $(NAME) $(OBJ)

%o: %c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
