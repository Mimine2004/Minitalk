/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 09:03:05 by hhecquet          #+#    #+#             */
/*   Updated: 2025/01/03 12:17:25 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_received_bit = 0;

char	*ft_realloc(char *message, size_t length)
{
	char	*tmp;
	
	tmp = malloc(sizeof(char) * length);
	if (!tmp)
	{
		free(message);
		// free(tmp);
		return (NULL);
	}
	memcpy(tmp, message, strlen(message));
	tmp[strlen(message)] = '\0';
	free(message);
	return (tmp);
}

void	signal_handler(int sig, siginfo_t *info, void *context)
{
	static int				bits_received = 0;
	static unsigned char	current_char = 0;
	static char				*message = NULL;
	static size_t			length = 1024;
	// char					*tmp;

	(void)context;
	// if (message) {
	// 	free(message);
	// }
	if (!message)
	{
		message = malloc(sizeof(char) * length);
		if (!message)
			return ;
	}
	if (sig == SIGUSR1)
		g_received_bit = 0;
	else if (sig == SIGUSR2)
		g_received_bit = 1;
	current_char = (current_char << 1) | g_received_bit;
	bits_received++;
	if (bits_received == 8)
	{
		if (strlen(message) >= length - 1)
		{
			length += 1024;
			message = ft_realloc(message, length);
			if (!message)
				return ;
		}
		message[strlen(message)] = current_char;
		if (current_char == '\0')
		{
			printf("%s\n", message);
			free(message);
			length = 0;
			message = NULL;
		}
		bits_received = 0;
		current_char = 0;
	}
	usleep(10);
	if (info && info->si_pid) {
		kill(info->si_pid, SIGUSR1);
	}
}

int	main(void)
{
	struct sigaction	sa;

	printf("PID du serveur : %d\n=-=-=-=-=-=-=-=-=-=-=-=\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		perror("sigaction SIGUSR1");
		return (1);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		perror("sigaction SIGUSR2");
		return (1);
	}
	while (1)
		pause();
	return (0);
}
