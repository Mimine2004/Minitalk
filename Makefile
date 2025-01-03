# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/02 08:17:15 by hhecquet          #+#    #+#              #
#    Updated: 2025/01/03 14:14:22 by hhecquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

CC = cc

SERVER = server
CLIENT = client

CFLAGS = -Wall -Wextra -Werror -g

SERVER_SRCS =	server.c	\
				libft/*c	\
				libft/ft_printf/*.c	
CLIENT_SRCS =	client.c	\
				libft/*c	\
				libft/ft_printf/*.c	

SERVER_BONUS =	server_bonus.c
CLIENT_BONUS =	client_bonus.c

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

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)
	@$(CC) $(CFLAGS) $(SERVER_BONUS) -o $(SERVER)
	@$(CC) $(CFLAGS) $(CLIENT_BONUS) -o $(CLIENT)
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