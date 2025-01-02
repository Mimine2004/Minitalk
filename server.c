/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 08:20:34 by hhecquet          #+#    #+#             */
/*   Updated: 2025/01/02 11:42:05 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t received_bit;

void signal_handler(int sig) {
    static int bit = 0;
    static char current_char = 0;
	static char *message = NULL;
	static size_t len = 0;
	static size_t i = 0;
	char *tmp;

	tmp = NULL;
	if (message == NULL)
	{
		len = 1024;
		message = malloc(sizeof(char)*len);
		if (!message)
			exit(1);
	}	
    if (sig == SIGUSR1)
        received_bit = 0;
    else if (sig == SIGUSR2)
        received_bit = 1;
    current_char = (current_char << 1) | received_bit;
    bit++;
    if (bit == 8)
	{
		if (i >= len)
		{
			len += 1024;
			tmp = malloc(sizeof(char)*len);
			if (!tmp)
			{
				free(message);
				exit(1);
			}
			strcpy(tmp, message);
			free(message);
			message = tmp;
		}	
        if (current_char == '\0')
		{
			message[i] = '\0';
            printf("%s\n", message);
			free(message);
			message = NULL;
			i = 0;
		}
		else
			message[i++] = current_char;
        current_char = 0;
        bit = 0;
    }
}

int main(void)
{
    printf("PID du serveur: %d\n", getpid());
    signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
    while (1)
        pause();
    return 0;
}
