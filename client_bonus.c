/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 09:01:36 by hhecquet          #+#    #+#             */
/*   Updated: 2025/01/03 17:36:25 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

volatile sig_atomic_t	g_ack = 0;

void	ack_handler(int sig)
{
	(void)sig;
	g_ack = 1;
}

int	send_message(pid_t server_pid, const char *message)
{
	size_t			i;
	unsigned char	c;
	int				bit;

	i = -1;
	while (++i <= strlen(message))
	{
		c = message[i];
		bit = -1;
		while (++bit < 8)
		{
			if (c & (1 << (7 - bit)))
			{
				if (kill(server_pid, SIGUSR2) == -1)
					return (-1);
			}
			else if (kill(server_pid, SIGUSR1) == -1)
				return (-1);
			while (!g_ack)
				pause();
			g_ack = 0;
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	pid_t				server_pid;
	struct sigaction	sa;

	server_pid = 0;
	if (argc != 3)
	{
		ft_printf("Usage: %s <server PID> <message>\n", argv[0]);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	sa.sa_handler = ack_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (1);
	if (send_message(server_pid, argv[2]) == -1)
		return (ft_printf("Wrong PID\n"), 0);
	while (!g_ack)
		pause();
	ft_printf("Message received !\n");
	return (0);
}
