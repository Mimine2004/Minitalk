/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 09:03:05 by hhecquet          #+#    #+#             */
/*   Updated: 2025/01/03 14:27:35 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_received_bit = 0;

char	*ft_realloc(char *message, size_t capacity, size_t len)
{
	char	*tmp;

	tmp = malloc(sizeof(char) * capacity);
	if (!tmp)
	{
		free(message);
		return (NULL);
	}
	ft_memcpy(tmp, message, len);
	free(message);
	return (tmp);
}

void	signal_handler(int sig, siginfo_t *info, void *context)
{
	static int				bits_received = 0;
	static unsigned char	current_char = 0;
	static char				*message = NULL;
	static size_t			capacity = 0;
	static size_t			len = 0;

	(void)context;
	if (sig == SIGUSR1)
		g_received_bit = 0;
	else if (sig == SIGUSR2)
		g_received_bit = 1;
	current_char = (current_char << 1) | g_received_bit;
	if (++bits_received == 8)
	{
		if (len + 1 >= capacity)
		{
			capacity += 1024;
			message = ft_realloc(message, capacity, len);
			if (!message)
				return ;
		}
		message[len] = current_char;
		len++;
		if (current_char == '\0')
		{
			ft_printf("%s\n", message);
			free(message);
			capacity = 0;
			len = 0;
			message = NULL;
		}
		bits_received = 0;
		current_char = 0;
	}
	usleep(10);
	if (info && info->si_pid)
		kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("PID du serveur : %d\n=-=-=-=-=-=-=-=-=-=-=-=\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		return (1);
	while (1)
		pause();
	return (0);
}
