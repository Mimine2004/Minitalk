# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/02 08:17:15 by hhecquet          #+#    #+#              #
#    Updated: 2025/01/02 11:33:32 by hhecquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

CC = cc

SERVER = server
CLIENT = client

CFLAGS = -Wall -Wextra -Werror

SERVER_SRCS =	server.c
CLIENT_SRCS =	client.c
		
SERVER_BONUS =	server_bonus.c
CLIENT_BONUS =	client_bonus.c

all: $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_SRCS)
	$(CC) $(CFLAGS) $(SERVER_SRCS) -o $(SERVER)
	@echo "$(SERVER) has been compiled successfully ! ✨"

$(CLIENT): $(CLIENT_SRCS)
	$(CC) $(CFLAGS) $(CLIENT_SRCS) -o $(CLIENT)
	@echo "$(CLIENT) has been compiled successfully ! ✨"

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)
	$(CC) $(CFLAGS) $(SERVER_BONUS) -o $(SERVER)
	$(CC) $(CFLAGS) $(CLIENT_BONUS) -o $(CLIENT)
	@echo "bonus have been compiled successfully ! 🌟"

clean: 
	rm -f *.o
	@echo "$(NAME)'s object files have been deleted ! 🔥"

fclean: clean
	rm -f $(SERVER) $(CLIENT)
	@echo "client and server themself have been deleted ! 💥"

re: fclean all

.PHONY : all clean fclean re