# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 17:38:51 by hhecquet          #+#    #+#              #
#    Updated: 2024/11/08 17:26:21 by hhecquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS =	ft_atoi.c		\
		ft_bzero.c		\
		ft_calloc.c		\
		ft_isalnum.c	\
		ft_isalpha.c	\
		ft_isalpha.c	\
		ft_isdigit.c	\
		ft_isascii.c	\
		ft_isprint.c	\
		ft_memchr.c		\
		ft_memcpy.c		\
		ft_memcmp.c		\
		ft_memmove.c	\
		ft_memset.c		\
		ft_strchr.c		\
		ft_strrchr.c	\
		ft_strdup.c		\
		ft_strlcat.c	\
		ft_strlcpy.c	\
		ft_strlen.c		\
		ft_strncmp.c	\
		ft_strnstr.c	\
		ft_tolower.c	\
		ft_toupper.c	\
		ft_strjoin.c	\
		ft_substr.c		\
		ft_strtrim.c	\
		ft_split.c		\
		ft_putchar_fd.c	\
		ft_putnbr_fd.c	\
		ft_putstr_fd.c	\
		ft_putendl_fd.c	\
		ft_itoa.c		\
		ft_striteri.c	\
		ft_strmapi.c	

BONUS = ft_lstnew_bonus.c		\
		ft_lstadd_front_bonus.c	\
		ft_lstsize_bonus.c		\
		ft_lstlast_bonus.c		\
		ft_lstadd_back_bonus.c	\
		ft_lstdelone_bonus.c	\
		ft_lstclear_bonus.c		\
		ft_lstiter_bonus.c		\
		ft_lstmap_bonus.c

OBJ = $(SRCS:.c=.o)

BONUS_OBJ = $(BONUS:_bonus.c=_bonus.o)

all: $(NAME)

$(NAME): $(OBJ) libft.h
	ar -rsc $(NAME) $(OBJ)

%o: %c 
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS_OBJ)
	ar -rsc $(NAME) $(BONUS_OBJ)

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all