/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:14:07 by hhecquet          #+#    #+#             */
/*   Updated: 2025/01/03 14:00:36 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	checkspace(t_flags flags)
{
	if (flags.space)
		return (ft_putchar(' '));
	return (0);
}

void	compareformatprecision(long long n, int sign, int zero, t_flags *flags)
{
	int	base;
	int	len;

	if (flags->flag == 'x' || flags->flag == 'X' || flags->flag == 'p')
		base = 16;
	else
		base = 10;
	if (flags->flag == 'p')
		len = ft_ptrlen(n, base);
	else
		len = ft_intlen(n, sign, base, zero);
	if (flags->precision > 0 && flags->precision + sign >= len)
		flags->precision = flags->precision + sign - len;
	else
		flags->precision = 0;
	if (flags ->formatsize <= flags->precision + len)
		flags->formatsize = 0;
	if (flags->formatsize > 0 && flags->formatsize > flags->precision + len)
		flags->formatsize = flags->formatsize - (flags->precision + len);
	if (flags->formatsize && sign && flags->zero)
	{
		flags->precision += flags->formatsize ;
		flags->formatsize = 0;
	}
}

int	ft_intlen(long long n, int sign, int base, int zero)
{
	int	len;

	len = 0;
	if (sign > 0 && !zero)
		len = 1;
	if (n == 0 && !zero)
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

int	parseprecision(const char *format, int i, t_flags *flags)
{
	flags->point = 1;
	flags->zero = 0;
	while (ft_isdigit(format[i]))
	{
		flags->precision = (flags->precision * 10) + (format[i] - '0');
		i++;
	}
	return (i);
}
