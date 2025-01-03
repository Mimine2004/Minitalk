# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/02 08:17:15 by hhecquet          #+#    #+#              #
#    Updated: 2025/01/03 14:58:06 by hhecquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

CC = cc

SERVER = server
CLIENT = client

SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

CFLAGS = -Wall -Wextra -Werror -g

SERVER_SRCS =	server.c	\
				libft/*c	\
				libft/ft_printf/*.c	
CLIENT_SRCS =	client.c	\
				libft/*c	\
				libft/ft_printf/*.c	

SERVER_BONUS_SRCS =	server_bonus.c	\
					libft/*c		\
					libft/ft_printf/*.c
CLIENT_BONUS_SRCS =	client_bonus.c	\
					libft/*c		\
					libft/ft_printf/*.c
				

all: $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_SRCS) minitalk.h
	@cd libft/ft_printf && make -s
	@cd ..
	@cd libft && make -s
	@cd ..
	@$(CC) $(CFLAGS) $(SERVER_SRCS) -o $(SERVER)
	@echo "$(SERVER) has been compiled successfully ! ✨"

$(CLIENT): $(CLIENT_SRCS) minitalk.h
	@cd libft/ft_printf && make -s
	@cd ..
	@cd libft && make -s
	@cd ..
	@$(CC) $(CFLAGS) $(CLIENT_SRCS) -o $(CLIENT)
	@echo "$(CLIENT) has been compiled successfully ! ⭐"

bonus: $(SERVER_BONUS_SRCS) $(CLIENT_BONUS_SRCS) minitalk_bonus.h
	@$(CC) $(CFLAGS) $(SERVER_BONUS_SRCS) -o $(SERVER_BONUS)
	@$(CC) $(CFLAGS) $(CLIENT_BONUS_SRCS) -o $(CLIENT_BONUS)
	@echo "bonus have been compiled successfully ! 🌟"

clean:
	@cd libft/ft_printf && make -s clean
	@cd ..
	@cd libft && make -s clean
	@cd ..
	@rm -f *.o
	@echo "$(NAME)'s object files have been deleted ! 🔥"

fclean:
	@cd libft/ft_printf && make -s fclean
	@cd ..
	@cd libft && make -s fclean
	@cd ..
	@make -s clean
	@rm -f $(SERVER) $(CLIENT)
	@echo "client and server themself have been deleted ! 💥"

re: fclean all

.PHONY : all clean fclean re