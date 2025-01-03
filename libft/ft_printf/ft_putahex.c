/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putahex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:25:04 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/25 14:14:07 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptrlen(unsigned long long n, int base)
{
	int	len;

	len = 0;
	if (n == 0)
		len += 1;
	while (n)
	{
		n /= base;
		len++;
	}
	if (len < 0)
		return (0);
	return (len);
}

void	ft_putahex(unsigned long long nb, int *len, char *base, t_flags *flags)
{
	while (flags->precision > 0)
	{
		*len += ft_putchar('0');
		flags->precision--;
	}
	if (nb >= 16)
		ft_putahex(nb / 16, len, base, flags);
	*len += ft_putchar(base[nb % 16]);
}

int	ft_putahash(unsigned long long n, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.hash == 1 && n != 0)
	{
		if (flags.flag == 'X')
			count += ft_putstr("0X");
		else
			count += ft_putstr("0x");
	}
	if (flags.flag == 'p')
		count += ft_putstr("0x");
	return (count);
}

int	ft_print_hex_prefix(unsigned long long n, t_flags flags, int *count)
{
	if (flags.flag == 'p' && !n)
	{
		if (!flags.minus && flags.formatsize > 5)
		{
			while (*count < flags.formatsize - 5)
				*count += write(1, " ", 1);
		}
		*count += write(1, "(nil)", 5);
		if (flags.minus && flags.formatsize > 5)
		{
			while (*count < flags.formatsize)
				*count += write(1, " ", 1);
		}
		return (1);
	}
	return (0);
}

int	ft_print_hex(unsigned long long n, t_flags flags)
{
	char	*hex;
	int		count;
	int		iszero;

	count = 0;
	if (ft_print_hex_prefix(n, flags, &count))
		return (count);
	iszero = (n == 0 && flags.point && flags.precision == 0);
	if (flags.flag == 'X')
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	compareformatprecision(n, 0, iszero, &flags);
	if (!flags.minus && flags.formatsize)
		count += putformat(flags.formatsize, flags);
	count += ft_putahash(n, flags);
	if (!iszero)
		ft_putahex(n, &count, hex, &flags);
	if (flags.minus && flags.formatsize)
		count += putformat(flags.formatsize, flags);
	return (count);
}
