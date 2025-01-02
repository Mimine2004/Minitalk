/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 08:20:26 by hhecquet          #+#    #+#             */
/*   Updated: 2025/01/02 13:47:22 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int send_char(pid_t server_pid, char *str, useconds_t delay)
{
	unsigned long i;
	int bits;

	i = 0;
	(void)delay;
    while (i <= strlen(str))
	{
		bits = 0;
		while (bits < 8)
		{
			if ((str[i] & (1 << (7 - bits))) != 0)
			{
				if (kill(server_pid, SIGUSR2) == -1)
                    return (-1);
			}
			else
			{
				if (kill(server_pid, SIGUSR1) == -1)
                    return (-1);
			}
			pause();
			bits++;
		}
		i++;
    }
	return (0);
}

int main(int argc, char **argv) 
{
	useconds_t delay = BASE_DELAY;
    if (argc != 3)
	{
        printf("Usage: %s <server PID> <message>\n", argv[0]);
        return (1);
    }
	delay += (DELAY_MULTIPLIER * (strlen(argv[2])));
	if (send_char(atoi(argv[1]), argv[2], delay) == -1)
	{
		printf("Wrong PID\n");
		return (1);
	}
    return (0);
}
