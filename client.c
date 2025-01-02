/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 08:20:26 by hhecquet          #+#    #+#             */
/*   Updated: 2025/01/02 11:17:34 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int send_char(pid_t server_pid, char *str)
{
	unsigned long i;
	int bits;

	i = 0;
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
			usleep(1000);
			bits++;
		}
		i++;
    }
	return (0);
}

int main(int argc, char **argv) 
{
    if (argc != 3)
	{
        printf("Usage: %s <server PID> <message>\n", argv[0]);
        return (1);
    }
	if (send_char(atoi(argv[1]), argv[2]) == -1)
	{
		printf("Wrong PID\n");
		return (1);
	}
    return (0);
}
