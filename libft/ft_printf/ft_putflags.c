/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 08:21:07 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/25 14:13:33 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_c(char c, t_flags flags)
{
	int	count;

	count = 0;
	if (!flags.minus && flags.formatsize > 1)
		count += putformat(flags.formatsize - 1, flags);
	count += ft_putchar(c);
	if (flags.minus && flags.formatsize > 1)
		count += putformat(flags.formatsize - 1, flags);
	return (count);
}

void	ft_putprecision(long nb, int *count, t_flags *flags)
{
	if (nb >= 0 && flags->plus == 1)
	{
		*count += ft_putchar('+');
		flags->plus = 0;
	}
	else if (nb < 0)
	{
		*count += ft_putchar('-');
		nb *= -1;
		flags->plus = 0;
	}
	while (flags->precision > 0)
	{
		*count += ft_putchar('0');
		flags->precision--;
	}
	if (nb >= 10)
		ft_putprecision(nb / 10, count, flags);
	*count += ft_putchar(nb % 10 + '0');
}

int	ft_putnbr(long nb, t_flags flags)
{
	int	sign;
	int	count;
	int	zero;

	count = 0;
	zero = 0;
	sign = handle_sign(nb, flags);
	if (sign == 0)
		count += checkspace(flags);
	if (nb == 0 && flags.point == 1 && flags.precision == 0)
		zero = 1;
	compareformatprecision(nb, sign, zero, &flags);
	if (zero == 1)
		return (count += putformat(flags.formatsize, flags));
	if (!flags.minus && flags.formatsize)
		count += putformat(flags.formatsize, flags);
	ft_putprecision(nb, &count, &flags);
	if (flags.minus && flags.formatsize)
		count += putformat(flags.formatsize, flags);
	return (count);
}

int	putformat(int len, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.space == 1 && len > 0 && ft_strchr("uid", flags.flag))
		len -= 1;
	if (flags.hash == 1 || flags.flag == 'p')
		len -= 2;
	while (len > 0)
	{
		if (flags.zero)
			count += ft_putchar('0');
		else
			count += ft_putchar(' ');
		len--;
	}
	return (count);
}

int	ft_putstr_len(char *str, int len)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i] && i < len)
		ft_putchar(str[i++]);
	return (i);
}
