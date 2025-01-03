/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:44:56 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/08 16:56:32 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		nb = nb * -1;
		ft_putchar_fd('-', fd);
	}
	if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd);
	}
	ft_putchar_fd((nb % 10) + '0', fd);
}
/* #include <unistd.h>
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
int main(void)
{
    ft_putnbr_fd(-6312,1);
	ft_putchar_fd('\n',1);
	ft_putnbr_fd(-2147483648,1);
    ft_putchar_fd('\n',1);
	ft_putnbr_fd(6312125,1);
    ft_putchar_fd('\n',1);
	ft_putnbr_fd(-0,1);
    ft_putchar_fd('\n',1);
    return (0);
} */
